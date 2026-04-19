/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:14:36 by tshimizu          #+#    #+#             */
/*   Updated: 2026/04/19 11:22:03 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "read.h"
#include "utils.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		fd;
	char	**lines;

	if (!validate_argv(argc, argv))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("Error\n"), 1);
	lines = read_file(fd);
	close(fd);
	if (!lines)
		return (ft_putstr_fd("Error\ncan't read_file\n", 2), 1);
	free_array(lines);
	return (0);
}
