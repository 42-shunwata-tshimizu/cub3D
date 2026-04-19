/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:16:04 by tshimizu          #+#    #+#             */
/*   Updated: 2026/04/19 20:06:32 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# define NOT_FOUND -1

# include "../libs/get_next_line/srcs/get_next_line.h"
# include "../libs/libft/libft.h"
# include "game.h"
# include "utils.h"
# include <stdbool.h>

char	**extract_map(char **lines, int start, int end);
bool	is_map_closed(char **map_copy);
bool	validate_map(char **lines, char **map, int start, int end);
bool	find_player(char **map, t_player *player);
t_game	*parse_map(char **lines, t_game *game);

#endif // PARSE_H
