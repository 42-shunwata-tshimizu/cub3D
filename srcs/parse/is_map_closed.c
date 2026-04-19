/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:54:48 by tshimizu          #+#    #+#             */
/*   Updated: 2026/04/19 20:06:14 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static bool	flood_fill_leaks(char **map_copy, int x, int y)
{
	if (x < 0 || y < 0 || !map_copy[y] || x >= (int)ft_strlen(map_copy[y]))
		return true;
	if (map_copy[y][x]==' ')
		return true;
	if (map_copy[y][x]=='1'||map_copy[y][x]=='V')
		return false;
	map_copy[y][x] = 'V';
	return (flood_fill(map_copy, x + 1, y) || flood_fill(map_copy, x - 1, y)
		|| flood_fill(map_copy, x, y + 1) || flood_fill(map_copy, x, y - 1));
}

bool	is_map_closed(char **map_copy)
{
	t_player	tmp_player;

	tmp_player.position_x = 0;
	tmp_player.position_y = 0;
	find_player(map_copy, &tmp_player);
	if (flood_fill_leaks(map_copy,tmp_player.position_x,tmp_player.position_x))
		return (false);
	return true;
}
