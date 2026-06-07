/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:53:41 by tshimizu          #+#    #+#             */
/*   Updated: 2026/06/06 20:00:28 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_game	*init_game_struct(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = ft_calloc(1, sizeof(t_map));
	game->player = ft_calloc(1, sizeof(t_player));
	game->keys = ft_calloc(1, sizeof(t_keys));
	if (!game->map || !game->player || !game->keys)
		return (free_game(game), NULL);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free_game(game), NULL);
	game->mlx_win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	if (!game->mlx_win)
		return (free_game(game), NULL);
	return (game);
}

static bool	init_image_struct(t_game *game)
{
	game->image.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->image.img)
		return (false);
	game->image.addr = mlx_get_data_addr(game->image.img, &game->image.bpp,
			&game->image.line_length, &game->image.endian);
	if (!game->image.addr)
		return (false);
	return (true);
}

static bool	load_texture(void *mlx, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(mlx, path, &texture->width,
			&texture->height);
	if (!texture->img)
		return (false);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_length, &texture->endian);
	if (!texture->addr)
		return (false);
	return (true);
}

static bool	init_textures_struct(t_game *game)
{
	if (!load_texture(game->mlx, &game->textures.north,
			game->map->north_texture))
		return (false);
	if (!load_texture(game->mlx, &game->textures.south,
			game->map->south_texture))
		return (false);
	if (!load_texture(game->mlx, &game->textures.west,
			game->map->west_texture))
		return (false);
	if (!load_texture(game->mlx, &game->textures.east,
			game->map->east_texture))
		return (false);
	return (true);
}

t_game	*setup_game(int argc, char *argv[])
{
	t_game	*game;
	char	**lines;

	if (!validate_argv(argc, argv))
		return (NULL);
	lines = load_map_file(argv[1]);
	if (!lines)
		return (NULL);
	game = init_game_struct();
	if (!game)
		return (free_array(lines), ft_putstr_fd("Error\nFaild to init_game\n",
				2), NULL);
	if (!init_image_struct(game))
		return (free_array(lines), free_game(game), NULL);
	if (!parse(lines, game))
		return (free_array(lines), free_game(game), NULL);
	if (!init_textures_struct(game))
		return (free_array(lines), free_game(game), NULL);
	free_array(lines);
	return (game);
}
