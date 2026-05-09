/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 14:37:38 by tshimizu          #+#    #+#             */
/*   Updated: 2026/05/09 14:37:41 by tshimizu         ###   ########.fr       */
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

bool	has_map_leak(char **map_copy)
{
	t_player	tmp_player;

	tmp_player.position_x = 0;
	tmp_player.position_y = 0;
	find_player(map_copy, &tmp_player);
	return (has_leak(map_copy, tmp_player.position_x, tmp_player.position_y));
}
