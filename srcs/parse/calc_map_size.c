/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_map_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:27:20 by tshimizu          #+#    #+#             */
/*   Updated: 2026/04/25 18:17:43 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	calc_map_size(t_game *game)
{
	int		width;
	int		height;
	char	*current_line;
	int		len;

	height = 0;
	width = 0;
	while (game->map->map_data[height])
	{
		len = ft_strlen(game->map->map_data[height]);
		if (width < len)
			width = ft_strlen(current_line);
		height++;
	}
	game->map->height = height;
	game->map->width = width;
}
