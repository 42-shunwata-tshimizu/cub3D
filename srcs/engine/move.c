/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:52:12 by tshimizu          #+#    #+#             */
/*   Updated: 2026/05/31 11:25:43 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static t_vec	get_input_direction(t_keys *keys)
{
	t_vec	dir;

	dir.x = 0;
	dir.y = 0;
	dir.y += keys->key_w;
	dir.y -= keys->key_s;
	dir.x += keys->key_d;
	dir.x -= keys->key_a;
	return (dir);
}

static void	move_player(t_game *game)
{
	t_vec	input;
	t_vec	move;

	input = get_input_direction(game->keys);
	move.x = 0;
	move.y = 0;
	move.x += game->player->dir_x * input.y;
	move.y += game->player->dir_y * input.y;
	move.x += game->player->plane_x * input.x;
	move.y += game->player->plane_y * input.x;
	game->player->position_x += move.x * MOVE_SPEED;
	game->player->position_y += move.y * MOVE_SPEED;
}

static double	get_rotate_input(t_keys *keys)
{
	double	rot;

	rot = 0;
	rot += keys->key_left;
	rot -= keys->key_right;
	return (rot);
}

static void	rotate_player(t_game *game)
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

void	update_player_state(t_game *game)
{
	move_player(game);
	rotate_player(game);
}
