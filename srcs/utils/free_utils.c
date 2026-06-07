/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:16:04 by tshimizu          #+#    #+#             */
/*   Updated: 2026/06/07 23:22:39 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	free_textures(t_game *game)
{
	if (!game->mlx)
		return ;
	if (game->textures.north.img)
		mlx_destroy_image(game->mlx, game->textures.north.img);
	if (game->textures.south.img)
		mlx_destroy_image(game->mlx, game->textures.south.img);
	if (game->textures.west.img)
		mlx_destroy_image(game->mlx, game->textures.west.img);
	if (game->textures.east.img)
		mlx_destroy_image(game->mlx, game->textures.east.img);
}

static void	free_image(t_game *game)
{
	if (game->mlx && game->image.img)
		mlx_destroy_image(game->mlx, game->image.img);
}

static void	free_map(t_map *map)
{
	if (!map)
		return ;
	free_array(map->map_data);
	free(map->north_texture);
	free(map->south_texture);
	free(map->west_texture);
	free(map->east_texture);
	free(map);
}

static void	free_mlx(t_game *game)
{
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_textures(game);
	free_image(game);
	free_map(game->map);
	free(game->player);
	free(game->keys);
	free_mlx(game);
	free(game);
}
