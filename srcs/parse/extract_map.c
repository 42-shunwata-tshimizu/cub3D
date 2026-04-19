/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:14:36 by tshimizu          #+#    #+#             */
/*   Updated: 2026/04/07 23:34:35 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "parse.h"

static bool is_map_line(char *line)
{
    int i;

    i = 0;

    if (!line || line[0]=='\0')
        return false;

    while (line[i]) {
        if(!ft_strchr("01NSEW ", line[i]))
            return false;
        i++;
    }
    return true;
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
	return (-1);
}

static int find_map_end(char **lines, int start)
{
    int i;
    i = start;

    while (lines[i] && is_map_line(lines[i]))
        i++;
    return (i);
}

static char **slice_lines(char **lines, int start, int end)
{
    int i;
    char **res;

    i = 0;
    res = malloc(sizeof(char *) * (end - start + 1));
    if (!res)
        return NULL;

    while (start < end)
        res[i++] = ft_strdup(lines[start++]);

    res[i] = NULL;
    return res;
}

//Todo textureでも使える汎用関数にできないか検討
char **extract_map(char **lines)
{
    int start;
    int end;
    int i;

    start = find_map_start(lines);
    if (start == -1)
        return NULL;

    end = find_map_end(lines, start);

    i = end;
    while (lines[i])
    {
        if (lines[i][0] != '\0')
            return NULL;
        i++;
    }

    return slice_lines(lines, start, end);
}
