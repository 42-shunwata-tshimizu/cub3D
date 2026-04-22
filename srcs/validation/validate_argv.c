/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:14:48 by tshimizu          #+#    #+#             */
/*   Updated: 2026/04/13 19:25:40 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static bool	has_cub_extension(const char *filename)
{
	int	len;

	if (!filename)
		return (false);
	len = ft_strlen(filename);
	if (len < 5)
		return (false);
	return (ft_strncmp(filename + len - 4, ".cub", 4) == 0);
}

bool	validate_argv(int ac, char *av[])
{
	if (ac != 2 || !av[1] || !av[1][0])
	{
		ft_putstr_fd("Error\nUsage: ./cub3D [file_path_of_the_map]\n", 2);
		return (false);
	}
	if (!has_cub_extension(av[1]))
		return (ft_putstr_fd("Error\nInvalid extension\n", 2), false);
	if (!is_readable(av[1]))
		return (ft_putstr_fd("Error\n", 2), perror("open failed"), false);
	return (true);
}
