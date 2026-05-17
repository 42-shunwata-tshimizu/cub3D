/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:14:36 by tshimizu          #+#    #+#             */
/*   Updated: 2026/05/17 14:31:14 by tshimizu         ###   ########.fr       */
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

static t_game	*setup_game(int argc, char *argv[])
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
	if (!parse(lines, game))
		return (free_array(lines), free_game(game), NULL);
	free_array(lines);
	return (game);
}

static void	register_hooks(t_game *game)
{
	mlx_hook(game->mlx_win, KEY_PRESS, KEY_PRESS_MASK, key_press, game);
	mlx_hook(game->mlx_win, KEY_RELEASE, KEY_RELEASE_MASK, key_release, game);
	mlx_hook(game->mlx_win, CLOSE_WINDOW, CLOSE_WINDOW_MASK, close_window,
		game);
}

static void	run_game(t_game *game)
{
	register_hooks(game);
	mlx_loop(game->mlx);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	game = setup_game(argc, argv);
	if (!game)
		return (1);
	run_game(game);
	return (0);
}
