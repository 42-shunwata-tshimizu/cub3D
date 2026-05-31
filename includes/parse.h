/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:47:47 by shunwata          #+#    #+#             */
/*   Updated: 2026/05/31 12:06:01 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "game.h"
# include "libft.h"
# include "utils.h"
# include "validation.h"
# include <stdbool.h>

# define MAP_CHAR_WALL '1'
# define MAP_CHAR_EMPTY ' '
# define MAP_CHAR_FLOOR '0'
# define MAP_CHAR_PLAYER "NSEW"
# define MAP_VALID_CHARS "01NSEW "

void	init_direction(t_player *player, char c);
void	calc_map_size(t_game *game);
char	**extract_map(char **lines, int start, int end);
bool	has_map_leak(char **map_copy);
bool	validate_map(char **lines, char **map, int start, int end);
bool	find_player(char **map, t_player *player);
t_game	*parse_map(char **lines, t_game *game);
bool	parse_texture(char **lines, t_map *map);
bool	parse_color(char **lines, t_map *map);

bool	parse(char **lines, t_game *game);

#endif // PARSE_H
