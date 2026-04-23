/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:16:04 by tshimizu          #+#    #+#             */
/*   Updated: 2026/04/23 22:50:21 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libs/libft/libft.h"
# include "game.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

void	free_array(char **arr);
void	free_game(t_game *game);
void	ft_noop(void *ptr);

bool	is_space(char c);
char	*skip_space(const char *line);

bool	is_readable(const char *filename);

#endif // UTILS_H
