/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 19:28:38 by tshimizu          #+#    #+#             */
/*   Updated: 2026/05/31 11:52:20 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static bool	is_player_cell(char c)
{
	return (ft_strchr(MAP_CHAR_PLAYER, c) != NULL);
}

static void	set_direction(
	t_player *player,
	double dir_x,
	double dir_y,
	double plane_x,
	double plane_y)
{
	player->dir_x = dir_x;
	player->dir_y = dir_y;
	player->plane_x = plane_x;
	player->plane_y = plane_y;
}

static void	init_direction(t_player *player, char c)
{
	if (c == 'N')
		set_direction(player, 0, -1, 0.66, 0);
	else if (c == 'S')
		set_direction(player, 0, 1, -0.66, 0);
	else if (c == 'E')
		set_direction(player, 1, 0, 0, 0.66);
	else if (c == 'W')
		set_direction(player, -1, 0, 0, -0.66);
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
