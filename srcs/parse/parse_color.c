/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 11:52:13 by shunwata          #+#    #+#             */
/*   Updated: 2026/05/07 12:00:10 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	rgb_to_int(char **rgb)
{
	return ((ft_atoi(rgb[0]) << 16) | (ft_atoi(rgb[1]) << 8)
		| ft_atoi(rgb[2]));
}

static int	get_color_value(char *line)
{
	char	**rgb;
	int		color;

	line = skip_space(line + 1);
	rgb = ft_split(line, ',');
	if (!rgb)
		return (ft_putstr_fd("Error\nmalloc failed\n", 2), -1);
	color = rgb_to_int(rgb);
	free_array(rgb);
	return (color);
}

static bool	parse_color_line(char *line, t_map *map)
{
	line = skip_space(line);
	if (line[0] == 'F' && is_space(line[1]))
	{
		map->floor_color = get_color_value(line);
		return (map->floor_color != NOT_FOUND);
	}
	if (line[0] == 'C' && is_space(line[1]))
	{
		map->ceiling_color = get_color_value(line);
		return (map->ceiling_color != NOT_FOUND);
	}
	return (true);
}

bool	parse_color(char **lines, t_map *map)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (!parse_color_line(lines[i], map))
			return (false);
		i++;
	}
	return (true);
}
