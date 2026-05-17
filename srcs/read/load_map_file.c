/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 12:16:31 by tshimizu          #+#    #+#             */
/*   Updated: 2026/05/17 12:16:55 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

char	**load_map_file(char *path)
{
	int		fd;
	char	**lines;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (perror("Error"), NULL);
	lines = read_file(fd);
	close(fd);
	if (!lines)
		return (ft_putstr_fd("Error\ncan't read_file\n", 2), NULL);
	return (lines);
}
