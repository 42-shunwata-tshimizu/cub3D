/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 19:28:38 by tshimizu          #+#    #+#             */
/*   Updated: 2026/04/19 19:44:29 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static bool	is_player_cell(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

bool	find_player(char **map, t_player *player)
{
	int	y;
	int	x;

	while (map[y])
	{
		x = 0;
		while (map[x])
		{
			if (is_player_cell(map[y][x]))
			{
				player->position_x = x;
				player->position_y = y;
				return (true);
			}
			x++;
		}
		y++;
	}
	return (false);
}
