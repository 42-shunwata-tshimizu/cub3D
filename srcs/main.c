/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:14:36 by tshimizu          #+#    #+#             */
/*   Updated: 2026/05/16 19:10:23 by tshimizu         ###   ########.fr       */
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
	return (game);
}

int	main(int argc, char *argv[])
{
	int		fd;
	char	**lines;
	t_game	*game;

	if (!validate_argv(argc, argv))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("Error\n"), 1);
	lines = read_file(fd);
	close(fd);
	if (!lines)
		return (ft_putstr_fd("Error\ncan't read_file\n", 2), 1);
	game = init_game_struct();
	if (!game)
		return (free_array(lines), ft_putstr_fd("Error\nFaild to init_game\n",
				2), 1);
	if (!parse(lines, game))
		return (free_array(lines), free_game(game), 1);
	mlx_hook(game->mlx_win, KEY_PRESS, KEY_PRESS_MASK, key_press, game);
	mlx_hook(game->mlx_win, KEY_RELEASE, KEY_RELEASE_MASK, key_release, game);
	mlx_loop(game->mlx);
	free_array(lines);
	free_game(game);
	return (0);
}
