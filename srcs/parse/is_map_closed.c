/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:54:48 by tshimizu          #+#    #+#             */
/*   Updated: 2026/04/25 16:47:52 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static bool	has_leak(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[y] || x >= (int)ft_strlen(map[y]))
		return (true);
	if (map[y][x] == ' ')
		return (true);
	if (map[y][x] == '1' || map[y][x] == 'V')
		return (false);
	map[y][x] = 'V';
	return (has_leak(map, x + 1, y) || has_leak(map, x - 1, y) || has_leak(map,
			x, y + 1) || has_leak(map, x, y - 1));
}

bool	is_map_closed(char **map_copy)
{
	t_player	tmp_player;

	tmp_player.position_x = 0;
	tmp_player.position_y = 0;
	find_player(map_copy, &tmp_player);
	if (!has_leak(map_copy, tmp_player.position_x, tmp_player.position_y))
		return (false);
	return (true);
}
