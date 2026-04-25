/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:16:04 by tshimizu          #+#    #+#             */
/*   Updated: 2026/04/25 13:19:11 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libs/minilibx-linux/mlx.h"
# include "game.h"
# include "libft.h"
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
