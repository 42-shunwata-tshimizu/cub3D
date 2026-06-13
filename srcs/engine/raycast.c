/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 16:32:57 by shunwata          #+#    #+#             */
/*   Updated: 2026/06/13 17:39:01 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "libft.h"
#include <math.h>

static void	init_ray(const t_game *game, int screen_x, t_ray *ray)
{
	t_vec2	dir;
	t_vec2	plane;

	ray->origin.x = game->player->position_x;
	ray->origin.y = game->player->position_y;
	dir = vec2(game->player->dir_x, game->player->dir_y);
	plane = vec2_scale(vec2_perpendicular(dir), 0.66);
	ray->camera_x = 2.0 * screen_x / (double)WIDTH - 1.0;
	ray->ray_dir = vec2_add(dir, vec2_scale(plane, ray->camera_x));
}

static void	init_dda(const t_ray *ray, t_dda *dda)
{
	dda->map_x = (int)ray->origin.x;
	dda->map_y = (int)ray->origin.y;
	dda->delta_dist_x = 1e30;
	dda->delta_dist_y = 1e30;
	if (ray->ray_dir.x != 0.0)
		dda->delta_dist_x = fabs(1.0 / ray->ray_dir.x);
	if (ray->ray_dir.y != 0.0)
		dda->delta_dist_y = fabs(1.0 / ray->ray_dir.y);
	dda->step_x = 1;
	dda->step_y = 1;
	dda->side_dist_x = (dda->map_x + 1.0 - ray->origin.x)
		* dda->delta_dist_x;
	dda->side_dist_y = (dda->map_y + 1.0 - ray->origin.y)
		* dda->delta_dist_y;
	if (ray->ray_dir.x < 0)
		dda->step_x = -1;
	if (ray->ray_dir.y < 0)
		dda->step_y = -1;
	if (ray->ray_dir.x < 0)
		dda->side_dist_x = (ray->origin.x - dda->map_x)
			* dda->delta_dist_x;
	if (ray->ray_dir.y < 0)
		dda->side_dist_y = (ray->origin.y - dda->map_y)
			* dda->delta_dist_y;
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
		if (dda->map_y < 0 || dda->map_y >= map->height || dda->map_x < 0)
			return ;
		if ((size_t)dda->map_x >= ft_strlen(map->map_data[dda->map_y]))
			return ;
		if (map->map_data[dda->map_y][dda->map_x] == '1'
			|| map->map_data[dda->map_y][dda->map_x] == ' ')
			return ;
	}
}

static void	set_wall_hit(t_ray *ray, const t_dda *dda)
{
	if (dda->hit_axis == HIT_VERTICAL_SIDE)
	{
		ray->wall_dist = dda->side_dist_x - dda->delta_dist_x;
		ray->wall_hit_pos = ray->origin.y + ray->wall_dist * ray->ray_dir.y;
		ray->face = WALL_EAST;
		if (dda->step_x > 0)
			ray->face = WALL_WEST;
	}
	else
	{
		ray->wall_dist = dda->side_dist_y - dda->delta_dist_y;
		ray->wall_hit_pos = ray->origin.x + ray->wall_dist * ray->ray_dir.x;
		ray->face = WALL_SOUTH;
		if (dda->step_y > 0)
			ray->face = WALL_NORTH;
	}
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
