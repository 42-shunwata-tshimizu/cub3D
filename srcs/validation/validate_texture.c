/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 00:50:23 by shunwata          #+#    #+#             */
/*   Updated: 2026/04/13 19:27:05 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static bool	is_texture_line(const char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0 && is_space(line[2]))
		return (true);
	if (ft_strncmp(line, "SO", 2) == 0 && is_space(line[2]))
		return (true);
	if (ft_strncmp(line, "WE", 2) == 0 && is_space(line[2]))
		return (true);
	if (ft_strncmp(line, "EA", 2) == 0 && is_space(line[2]))
		return (true);
	return (false);
}

static bool	is_texture_path_valid(const char *path)
{
	int	len;

	if (!path || !path[0])
		return (ft_putstr_fd("Error\nTexture path is missing\n", 2), false);
	len = 0;
	while (path[len] && !is_space(path[len]))
		len++;
	if (path[len] != '\0' && path[len] != '\n')
		return (ft_putstr_fd("Error\nTexture path is invalid\n", 2), false);
	if (!is_readable(path))
		return (perror("Error\nCannot open texture file"), false);
	return (true);
}

static bool	register_texture(char *line, t_texture_state *state)
{
	char	*path;

	if (ft_strncmp(line, "NO", 2) == 0 && state->north)
		return (ft_putstr_fd("Error\nDuplicate NO texture\n", 2), false);
	if (ft_strncmp(line, "SO", 2) == 0 && state->south)
		return (ft_putstr_fd("Error\nDuplicate SO texture\n", 2), false);
	if (ft_strncmp(line, "WE", 2) == 0 && state->west)
		return (ft_putstr_fd("Error\nDuplicate WE texture\n", 2), false);
	if (ft_strncmp(line, "EA", 2) == 0 && state->east)
		return (ft_putstr_fd("Error\nDuplicate EA texture\n", 2), false);
	path = skip_space(line + 2);
	if (!is_texture_path_valid(path))
		return (false);
	if (ft_strncmp(line, "NO", 2) == 0)
		state->north = true;
	if (ft_strncmp(line, "SO", 2) == 0)
		state->south = true;
	if (ft_strncmp(line, "WE", 2) == 0)
		state->west = true;
	if (ft_strncmp(line, "EA", 2) == 0)
		state->east = true;
	return (true);
}

static bool	validate_texture_lines(char **lines, t_texture_state *state)
{
	char	*trimmed;
	int		index;

	index = 0;
	while (lines[index])
	{
		trimmed = skip_space(lines[index]);
		if (is_texture_line(trimmed) && !register_texture(trimmed, state))
			return (false);
		index++;
	}
	return (true);
}

bool	validate_texture(char **lines)
{
	t_texture_state	state;

	ft_bzero(&state, sizeof(t_texture_state));
	if (!validate_texture_lines(lines, &state))
		return (false);
	if (!state.north || !state.south || !state.west || !state.east)
		return (ft_putstr_fd("Error\nTexture is missing\n", 2), false);
	return (true);
}
