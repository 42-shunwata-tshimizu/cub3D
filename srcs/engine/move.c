/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 15:52:12 by tshimizu          #+#    #+#             */
/*   Updated: 2026/05/31 14:36:40 by tshimizu         ###   ########.fr       */
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

static void	update_position(t_game *game, double new_x, double new_y)
{
	if (is_walkable(game, new_x, game->player->position_y))
		game->player->position_x = new_x;
	if (is_walkable(game, game->player->position_x, new_y))
		game->player->position_y = new_y;
}

static void	move_player(t_game *game)
{
	t_vec	input;
	t_vec	move;
	double	new_x;
	double	new_y;

	input = get_input_direction(game->keys);
	move.x = 0;
	move.y = 0;
	move.x += game->player->dir_x * input.y;
	move.y += game->player->dir_y * input.y;
	move.x += game->player->plane_x * input.x;
	move.y += game->player->plane_y * input.x;
	new_x = game->player->position_x + move.x * MOVE_SPEED;
	new_y = game->player->position_y + move.y * MOVE_SPEED;
	update_position(game, new_x, new_y);
}

void	update_player_state(t_game *game)
{
	move_player(game);
	rotate_player(game);
}
