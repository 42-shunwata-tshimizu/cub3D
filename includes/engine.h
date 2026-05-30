/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 16:32:36 by shunwata          #+#    #+#             */
/*   Updated: 2026/05/17 16:32:42 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "game.h"
# include "vector.h"

typedef enum e_wall_face
{
	WALL_NORTH,
	WALL_SOUTH,
	WALL_WEST,
	WALL_EAST
}				t_wall_face;

typedef struct s_ray
{
	double		camera_x;
	t_vec2		ray_dir;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		wall_dist;
	double		wall_x;
	int			side;
	t_wall_face	face;
}				t_ray;

void			cast_ray(const t_game *game, int screen_x, t_ray *ray);

#endif // ENGINE_H
