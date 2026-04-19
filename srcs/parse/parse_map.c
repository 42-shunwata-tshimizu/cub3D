/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:14:36 by tshimizu          #+#    #+#             */
/*   Updated: 2026/04/19 19:26:29 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static bool	is_map_line(char *line)
{
	int	i;

	i = 0;
	if (!line || line[0] == '\0')
		return (false);
	while (line[i])
	{
		if (!ft_strchr("01NSEW ", line[i]))
			return (false);
		i++;
	}
	return (true);
}

static int	find_map_start(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (is_map_line(lines[i]))
			return (i);
		i++;
	}
	return (NOT_FOUND);
}

static int	find_map_end(char **lines, int start)
{
	int	i;

	i = start;
	while (lines[i] && is_map_line(lines[i]))
		i++;
	return (i);
}
char	**extract_map(char **lines, int start, int end)
{
	int		i;
	char	**res;

	i = 0;
	res = malloc(sizeof(char *) * (end - start + 1));
	if (!res)
		return (NULL);
	while (start < end)
	{
		res[i++] = ft_strdup(lines[start++]);
		if (!res[i])
		{
			while (i > 0)
				free(res[--i]);
			free(res);
			return (NULL);
		}
	}
	res[i] = NULL;
	return (res);
}

t_game	*parse_map(char **lines, t_game *game)
{
	int		start;
	int		end;
	char	**map;

	start = find_map_start(lines);
	if (start == NOT_FOUND)
		return (ft_putstr_fd("Error\nInvalid map not found\n", 2), NULL);
	end = find_map_end(lines, start);
	map = extract_map(lines, start, end);
	if (!map)
		return (NULL);
	if (!validate_map)
		return (free(map), NULL);
	game->map->map_data = map;
	return (game);
}
