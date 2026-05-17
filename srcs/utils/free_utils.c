/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:16:04 by tshimizu          #+#    #+#             */
/*   Updated: 2026/05/17 14:24:34 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_noop(void *ptr)
{
	(void)ptr;
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
	{
		if (game->map->map_data)
			free_array(game->map->map_data);
		free(game->map->north_texture);
		free(game->map->south_texture);
		free(game->map->west_texture);
		free(game->map->east_texture);
		free(game->map);
	}
	if (game->player)
		free(game->player);
	if (game->keys)
		free(game->keys);
	if (game ->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}
