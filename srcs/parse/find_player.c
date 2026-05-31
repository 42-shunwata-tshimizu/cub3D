/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 19:28:38 by tshimizu          #+#    #+#             */
/*   Updated: 2026/05/31 12:06:10 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static bool	is_player_cell(char c)
{
	return (ft_strchr(MAP_CHAR_PLAYER, c) != NULL);
}

bool	find_player(char **map, t_player *player)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (is_player_cell(map[y][x]))
			{
				player->position_x = x + 0.5;
				player->position_y = y + 0.5;
				init_direction(player, map[y][x]);
				return (true);
			}
			x++;
		}
		y++;
	}
	return (false);
}
