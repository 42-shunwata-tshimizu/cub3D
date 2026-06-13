/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 16:32:36 by shunwata          #+#    #+#             */
/*   Updated: 2026/06/13 17:06:59 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H
# define MOVE_SPEED 0.05
# define ROTATE_SPEED 0.04
# define PLAYER_RADIUS 0.2

# include "game.h"
# include "vector.h"
#include "libft.h"
# include <math.h>

typedef enum e_wall_face
{
	WALL_NORTH,
	WALL_SOUTH,
	WALL_WEST,
	WALL_EAST
}					t_wall_face;

typedef struct s_ray
{
	t_coordinate	origin;
	double			camera_x;
	t_vec2			ray_dir;
	double			wall_dist;
	double			wall_hit_pos;
	t_wall_face		face;
}					t_ray;

bool				is_walkable(t_game *game, double x, double y);
void				rotate_player(t_game *game);
void				update_player_state(t_game *game);
t_ray				cast_ray(const t_game *game, int screen_x);

#endif // ENGINE_H
