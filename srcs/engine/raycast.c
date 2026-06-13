/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 16:32:57 by shunwata          #+#    #+#             */
/*   Updated: 2026/06/13 16:59:42 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "libft.h"
#include <math.h>

typedef enum e_hit_axis
{
	HIT_VERTICAL_SIDE,
	HIT_HORIZONTAL_SIDE
}					t_hit_axis;

typedef struct s_dda
{
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	t_hit_axis		hit_axis;
}					t_dda;

static double	get_axis_delta_dist(double ray_dir)
{
	if (ray_dir == 0.0)
		return (1e30);
	return (fabs(1.0 / ray_dir));
}

static t_coordinate	get_ray_origin(const t_game *game)
{
	t_coordinate	origin;

	origin.x = game->player->position_x;
	origin.y = game->player->position_y;
	return (origin);
}

static void	init_ray(const t_game *game, int screen_x, t_ray *ray)
{
	t_vec2	dir;
	t_vec2	plane;

	ray->origin = get_ray_origin(game);
	dir = vec2(game->player->dir_x, game->player->dir_y);
	plane = vec2_scale(vec2_perpendicular(dir), 0.66);
	ray->camera_x = 2.0 * screen_x / (double)WIDTH - 1.0;
	ray->ray_dir = vec2_add(dir, vec2_scale(plane, ray->camera_x));
}

static void	init_dda(const t_ray *ray, t_dda *dda)
{
	dda->map_x = (int)ray->origin.x;
	dda->map_y = (int)ray->origin.y;
	dda->delta_dist_x = get_axis_delta_dist(ray->ray_dir.x);
	dda->delta_dist_y = get_axis_delta_dist(ray->ray_dir.y);
	if (ray->ray_dir.x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (ray->origin.x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - ray->origin.x)
			* dda->delta_dist_x;
	}
	if (ray->ray_dir.y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (ray->origin.y - dda->map_y) * dda->delta_dist_y;
		return ;
	}
	dda->step_y = 1;
	dda->side_dist_y = (dda->map_y + 1.0 - ray->origin.y) * dda->delta_dist_y;
}

static bool	is_wall(const t_map *map, int x, int y)
{
	size_t	row_len;

	if (y < 0 || y >= map->height || x < 0)
		return (true);
	row_len = ft_strlen(map->map_data[y]);
	if (x >= (int)row_len)
		return (true);
	return (map->map_data[y][x] == '1' || map->map_data[y][x] == ' ');
}

static void	set_vertical_hit(t_ray *ray, const t_dda *dda)
{
	ray->wall_dist = dda->side_dist_x - dda->delta_dist_x;
	ray->wall_hit_pos = ray->origin.y + ray->wall_dist * ray->ray_dir.y;
	ray->face = WALL_EAST;
	if (dda->step_x > 0)
		ray->face = WALL_WEST;
}

static void	set_horizontal_hit(t_ray *ray, const t_dda *dda)
{
	ray->wall_dist = dda->side_dist_y - dda->delta_dist_y;
	ray->wall_hit_pos = ray->origin.x + ray->wall_dist * ray->ray_dir.x;
	ray->face = WALL_SOUTH;
	if (dda->step_y > 0)
		ray->face = WALL_NORTH;
}

static void	walk_ray(const t_map *map, t_dda *dda)
{
	while (true)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			dda->hit_axis = HIT_VERTICAL_SIDE;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			dda->hit_axis = HIT_HORIZONTAL_SIDE;
		}
		if (is_wall(map, dda->map_x, dda->map_y))
			return ;
	}
}

static void	set_wall_hit(t_ray *ray, const t_dda *dda)
{
	if (dda->hit_axis == HIT_VERTICAL_SIDE)
		set_vertical_hit(ray, dda);
	else
		set_horizontal_hit(ray, dda);
	ray->wall_hit_pos -= floor(ray->wall_hit_pos);
}

t_ray	cast_ray(const t_game *game, int screen_x)
{
	t_ray	ray;
	t_dda	dda;

	init_ray(game, screen_x, &ray);
	init_dda(&ray, &dda);
	walk_ray(game->map, &dda);
	set_wall_hit(&ray, &dda);
	return (ray);
}
