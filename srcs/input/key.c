/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 11:16:32 by tshimizu          #+#    #+#             */
/*   Updated: 2026/05/16 19:44:38 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static bool	*get_key_state(t_keys *keys, t_key_codes keycode)
{
	if (keycode == KEY_W)
		return (&keys->key_w);
	if (keycode == KEY_A)
		return (&keys->key_a);
	if (keycode == KEY_S)
		return (&keys->key_s);
	if (keycode == KEY_D)
		return (&keys->key_d);
	if (keycode == KEY_LEFT)
		return (&keys->key_left);
	if (keycode == KEY_RIGHT)
		return (&keys->key_right);
	if (keycode == KEY_ESC)
		return (&keys->key_esc);
	return (NULL);
}
static void	set_key_state(t_game *game, t_key_codes keycode, bool value)
{
	bool	*state;

	state = get_key_state(game->keys, keycode);
	if (state)
		*state = value;
}

int	key_press(t_key_codes keycode, t_game *game)
{
	set_key_state(game, keycode, true);
	return (0);
}

int	key_release(t_key_codes keycode, t_game *game)
{
	set_key_state(game, keycode, false);
	return (0);
}
