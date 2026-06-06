/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 16:32:57 by shunwata          #+#    #+#             */
/*   Updated: 2026/05/17 16:32:59 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "libft.h"
#include <math.h>

static double	get_delta_dist(double ray_dir)
{
	if (ray_dir == 0.0)
		return (1e30);
	return (fabs(1.0 / ray_dir));
}

static t_coordinate	get_player_center(const t_game *game)
{
	t_coordinate	player;

	player.x = game->player->position_x;
	player.y = game->player->position_y;
	return (player);
}

static void	set_ray_start(const t_game *game, int screen_x, t_ray *ray)
{
	t_vec2	dir;
	t_vec2	plane;

	ray->player = get_player_center(game);
	dir = vec2(game->player->dir_x, game->player->dir_y);
	plane = vec2_scale(vec2_perpendicular(dir), 0.66);
	ray->camera_x = 2.0 * screen_x / (double)WIDTH - 1.0;
	ray->ray_dir = vec2_add(dir, vec2_scale(plane, ray->camera_x));
	ray->map_x = (int)ray->player.x;
	ray->map_y = (int)ray->player.y;
	ray->delta_dist_x = get_delta_dist(ray->ray_dir.x);
	ray->delta_dist_y = get_delta_dist(ray->ray_dir.y);
}

static void	set_ray_step(t_ray *ray)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->player.x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->player.x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->player.y - ray->map_y)
			* ray->delta_dist_y;
		return ;
	}
	ray->step_y = 1;
	ray->side_dist_y = (ray->map_y + 1.0 - ray->player.y)
		* ray->delta_dist_y;
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

static void	set_x_hit(t_ray *ray)
{
	ray->wall_dist = (ray->map_x - ray->player.x
			+ (1 - ray->step_x) / 2.0) / ray->ray_dir.x;
	ray->wall_x = ray->player.y + ray->wall_dist * ray->ray_dir.y;
	ray->face = WALL_EAST;
	if (ray->step_x > 0)
		ray->face = WALL_WEST;
}

static void	set_y_hit(t_ray *ray)
{
	ray->wall_dist = (ray->map_y - ray->player.y
			+ (1 - ray->step_y) / 2.0) / ray->ray_dir.y;
	ray->wall_x = ray->player.x + ray->wall_dist * ray->ray_dir.x;
	ray->face = WALL_SOUTH;
	if (ray->step_y > 0)
		ray->face = WALL_NORTH;
}

static void	walk_ray(const t_map *map, t_ray *ray)
{
	while (true)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (is_wall(map, ray->map_x, ray->map_y))
			return ;
	}
}

static void	set_hit(t_ray *ray)
{
	if (ray->side == 0)
		set_x_hit(ray);
	else
		set_y_hit(ray);
	ray->wall_x -= floor(ray->wall_x);
}

void	cast_ray(const t_game *game, int screen_x, t_ray *ray)
{
	set_ray_start(game, screen_x, ray);
	set_ray_step(ray);
	walk_ray(game->map, ray);
	set_hit(ray);
}
