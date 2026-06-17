/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:16:04 by tshimizu          #+#    #+#             */
/*   Updated: 2026/06/15 11:06:53 by shunwata         ###   ########.fr       */
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

void	put_pixel(t_image *image, int x, int y, int color);
int		get_wall_top(int line_height);
int		get_wall_bottom(int line_height);
int		get_tex_y(int y, int line_height, int texture_height);

#endif // UTILS_H
