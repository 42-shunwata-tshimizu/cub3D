/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 14:27:10 by tshimizu          #+#    #+#             */
/*   Updated: 2026/05/31 14:27:42 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static double	get_rotate_input(t_keys *keys)
{
	double	rot;

	rot = 0;
	rot += keys->key_left;
	rot -= keys->key_right;
	return (rot);
}

void	rotate_player(t_game *game)
{
	double	rot;
	double	old_dir_x;
	double	old_plane_x;
	double	cos_r;
	double	sin_r;

	rot = get_rotate_input(game->keys) * ROTATE_SPEED;
	cos_r = cos(rot);
	sin_r = sin(rot);
	old_dir_x = game->player->dir_x;
	game->player->dir_x = game->player->dir_x * cos_r - game->player->dir_y
		* sin_r;
	game->player->dir_y = old_dir_x * sin_r + game->player->dir_y * cos_r;
	old_plane_x = game->player->plane_x;
	game->player->plane_x = game->player->plane_x * cos_r
		- game->player->plane_y * sin_r;
	game->player->plane_y = old_plane_x * sin_r + game->player->plane_y * cos_r;
}
