/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 16:32:36 by shunwata          #+#    #+#             */
/*   Updated: 2026/05/31 18:57:15 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H
# define MOVE_SPEED 0.05
# define ROTATE_SPEED 0.04
# define PLAYER_RADIUS 0.2

# include "game.h"
# include "vector.h"
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
	t_coordinate	player;
	double			camera_x;
	t_vec2			ray_dir;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	double			wall_dist;
	double			wall_x;
	int				side;
	t_wall_face		face;
}					t_ray;

typedef struct s_vec
{
	double			x;
	double			y;
}					t_vec;

bool				is_walkable(t_game *game, double x, double y);
void				rotate_player(t_game *game);
void				update_player_state(t_game *game);
void				cast_ray(const t_game *game, int screen_x, t_ray *ray);

#endif // ENGINE_H
