/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 10:31:39 by tshimizu          #+#    #+#             */
/*   Updated: 2026/05/31 10:38:50 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	register_hooks(t_game *game)
{
	mlx_hook(game->mlx_win, KEY_PRESS, KEY_PRESS_MASK, key_press, game);
	mlx_hook(game->mlx_win, KEY_RELEASE, KEY_RELEASE_MASK, key_release, game);
	mlx_hook(game->mlx_win, CLOSE_WINDOW, CLOSE_WINDOW_MASK, close_window,
		game);
}

static int	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	update_player_state(game);
	return (0);
}

void	run_game(t_game *game)
{
	register_hooks(game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_loop(game->mlx);
}
