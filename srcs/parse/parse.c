/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:55:29 by shunwata          #+#    #+#             */
/*   Updated: 2026/04/25 16:48:15 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "parse.h"

bool	parse(char **lines, t_game *game)
{
	if (!validate_texture(lines))
		return (false);
	if (!parse_map(lines, game))
		return (false);
	return (true);
}
