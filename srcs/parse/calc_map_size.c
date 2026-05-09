/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_map_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:27:20 by tshimizu          #+#    #+#             */
/*   Updated: 2026/04/25 18:39:54 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	calc_map_size(t_game *game)
{
	int		width;
	int		height;
	int		len;

	height = 0;
	width = 0;
	while (game->map->map_data[height])
	{
		len = (int)ft_strlen(game->map->map_data[height]);
		if (width < len)
			width = len;
		height++;
	}
	game->map->height = height;
	game->map->width = width;
}
