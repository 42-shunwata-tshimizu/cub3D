/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 13:26:41 by tshimizu          #+#    #+#             */
/*   Updated: 2026/06/13 17:12:34 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static bool	is_empty(t_game *game, double x, double y)
{
	int		ix;
	int		iy;
	size_t	row_len;

	ix = (int)x;
	iy = (int)y;
	if (iy < 0 || iy >= game->map->height || ix < 0)
		return (false);
	row_len = ft_strlen(game->map->map_data[iy]);
	if (ix >= (int)row_len)
		return (false);
	return (game->map->map_data[iy][ix] != MAP_CHAR_WALL
		&& game->map->map_data[iy][ix] != MAP_CHAR_EMPTY);
}

bool	is_walkable(t_game *game, double x, double y)
{
	return (is_empty(game, x + PLAYER_RADIUS, y + PLAYER_RADIUS)
		&& is_empty(game, x + PLAYER_RADIUS, y - PLAYER_RADIUS)
		&& is_empty(game, x - PLAYER_RADIUS, y + PLAYER_RADIUS)
		&& is_empty(game, x - PLAYER_RADIUS, y - PLAYER_RADIUS));
}
