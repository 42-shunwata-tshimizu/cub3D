/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 13:26:41 by tshimizu          #+#    #+#             */
/*   Updated: 2026/05/31 14:08:05 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static bool	is_empty(t_game *game, double x, double y)
{
	char	cell;

	cell = game->map->map_data[(int)y][(int)x];
	return (cell != MAP_CHAR_WALL && cell != MAP_CHAR_EMPTY);
}

bool	is_walkable(t_game *game, double x, double y)
{
	return (is_empty(game, x + PLAYER_RADIUS, y + PLAYER_RADIUS)
		&& is_empty(game, x + PLAYER_RADIUS, y - PLAYER_RADIUS)
		&& is_empty(game, x - PLAYER_RADIUS, y + PLAYER_RADIUS)
		&& is_empty(game, x - PLAYER_RADIUS, y - PLAYER_RADIUS));
}
