/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:14:36 by tshimizu          #+#    #+#             */
/*   Updated: 2026/04/25 16:47:41 by tshimizu         ###   ########.fr       */
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
	if (!game->map || !game->player)
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
	free_array(lines);
	free_game(game);
	return (0);
}
