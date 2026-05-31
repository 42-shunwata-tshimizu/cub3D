/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:51:12 by tshimizu          #+#    #+#             */
/*   Updated: 2026/05/23 18:03:31 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H
# define MOVE_SPEED 0.05
# define ROTATE_SPEED 0.04

# include "game.h"
# include <math.h>

typedef struct s_vec
{
	double	x;
	double	y;
}			t_vec;

void		update_player_state(t_game *game);

#endif // ENGINE_H
