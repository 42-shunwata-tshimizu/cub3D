/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:51:12 by tshimizu          #+#    #+#             */
/*   Updated: 2026/05/31 14:38:40 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H
# define MOVE_SPEED 0.05
# define ROTATE_SPEED 0.04
# define PLAYER_RADIUS 0.2

# include "game.h"
# include <math.h>

typedef struct s_vec
{
	double	x;
	double	y;
}			t_vec;

bool		is_walkable(t_game *game, double x, double y);
void		rotate_player(t_game *game);
void		update_player_state(t_game *game);

#endif // ENGINE_H
