/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 11:16:49 by tshimizu          #+#    #+#             */
/*   Updated: 2026/05/16 19:08:48 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "game.h"

int	key_press(t_key_codes keycode, t_game *game);

int	key_release(t_key_codes keycode, t_game *game);

#endif // INPUT_H
