/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:14:36 by tshimizu          #+#    #+#             */
/*   Updated: 2026/04/19 20:07:56 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static bool	has_empty_after(char **lines, int end)
{
	int	i;

	i = end;
	while (lines[i])
	{
		if (lines[i][0] != '\0')
			return (true);
		i++;
	}
	return (false);
}

static bool	check_cell(char c, int *p)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		(*p)++;
	else if (c != '0' && c != '1' && c != ' ')
		return (false);
	return (true);
}

static bool	check_elements(char **map)
{
	int	y;
	int	x;
	int	p;

	y = 0;
	p = 0;
	while (map[y])
	{
		x = 0;
		while (map[x])
		{
			if (!check_cell(map[y][x], &p))
				return (false);
			x++;
		}
		y++;
	}
	return (p == 1);
}

bool	validate_map(char **lines, char **map, int start, int end)
{
	char	**map_copy;

	if (!has_empty_after(lines, end))
		return (ft_putstr_fd("Error\nInvalid map tail\n", 2), false);
	if (!check_elements(map))
		return (ft_putstr_fd("Error\nInvalid map elements\n", 2), false);
	map_copy = extract_map(lines, start, end);
	if (!map_copy)
		return (false);
	if (is_map_closed(map_copy))
		return (free_array(map_copy), ft_putstr_fd("Error\nInvalid map leaks\n",
				2), false);
	free_array(map_copy);
	return (true);
}
