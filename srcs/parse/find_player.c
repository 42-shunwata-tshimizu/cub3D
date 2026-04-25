/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 19:28:38 by tshimizu          #+#    #+#             */
/*   Updated: 2026/04/25 12:01:47 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static bool	is_player_cell(char c)
{
	return (ft_strchr(MAP_CHAR_PLAYER, c) != NULL);
}

static void	init_direction(t_player *player, char c)
{
	if (c == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (c == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (c == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (c == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
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
				player->position_x = x;
				player->position_y = y;
				init_direction(player, map[y][x]);
				return (true);
			}
			x++;
		}
		y++;
	}
	return (false);
}
