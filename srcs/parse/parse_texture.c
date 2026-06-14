/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 11:52:13 by shunwata          #+#    #+#             */
/*   Updated: 2026/06/14 14:35:31 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static char	*get_texture_path(char *line)
{
	char	*start;
	char	*end;
	char	*path;

	start = skip_space(line + 2);
	end = start;
	while (*end && !is_space(*end))
		end++;
	if (end == start)
		return (ft_putstr_fd("Error\nTexture path is missing\n", 2), NULL);
	if (skip_space(end)[0] != '\0')
		return (ft_putstr_fd("Error\nTexture path is invalid\n", 2), NULL);
	path = ft_substr(start, 0, end - start);
	if (!path)
		ft_putstr_fd("Error\nmalloc failed\n", 2);
	return (path);
}

static bool	parse_texture_line(char *line, t_map *map)
{
	line = skip_space(line);
	if (ft_strncmp(line, "NO", 2) == 0 && is_space(line[2]))
	{
		map->north_texture = get_texture_path(line);
		return (map->north_texture != NULL);
	}
	if (ft_strncmp(line, "SO", 2) == 0 && is_space(line[2]))
	{
		map->south_texture = get_texture_path(line);
		return (map->south_texture != NULL);
	}
	if (ft_strncmp(line, "WE", 2) == 0 && is_space(line[2]))
	{
		map->west_texture = get_texture_path(line);
		return (map->west_texture != NULL);
	}
	if (ft_strncmp(line, "EA", 2) == 0 && is_space(line[2]))
	{
		map->east_texture = get_texture_path(line);
		return (map->east_texture != NULL);
	}
	return (true);
}

bool	parse_texture(char **lines, t_map *map)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (!parse_texture_line(lines[i], map))
			return (false);
		i++;
	}
	return (true);
}
