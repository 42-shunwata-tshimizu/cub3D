/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:47:47 by shunwata          #+#    #+#             */
/*   Updated: 2026/04/23 22:49:46 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# define NOT_FOUND -1

# include "libft.h"
# include "game.h"
# include "utils.h"
# include "validation.h"
# include <stdbool.h>

char	**extract_map(char **lines, int start, int end);
bool	is_map_closed(char **map_copy);
bool	validate_map(char **lines, char **map, int start, int end);
bool	find_player(char **map, t_player *player);
t_game	*parse_map(char **lines, t_game *game);

bool	parse(char **lines,t_game *game);

#endif // PARSE_H
