/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 00:50:23 by shunwata          #+#    #+#             */
/*   Updated: 2026/04/10 00:52:30 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

bool	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

char	*skip_space(const char *line)
{
	while (*line && is_space(*line))
		line++;
	return ((char *)line);
}

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
	int	fd;
	int	len;

	if (!path || !path[0])
		return (ft_putstr_fd("Error\nTexture path is missing\n", 2), false);
	len = 0;
	while (path[len] && !is_space(path[len]))
		len++;
	if (path[len] != '\0' && path[len] != '\n')
		return (ft_putstr_fd("Error\nTexture path is invalid\n", 2), false);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (perror("Error"), false);
	close(fd);
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

static bool	validate_texture_lines(int fd, t_texture_state *state)
{
	char	*line;
	char	*trimmed;

	line = get_next_line(fd);
	while (line)
	{
		trimmed = skip_space(line);
		if (is_texture_line(trimmed) && !register_texture(trimmed, state))
			return (free(line), false);
		free(line);
		line = get_next_line(fd);
	}
	return (true);
}

bool	validate_texture(const char *filename)
{
	int				fd;
	t_texture_state	state;

	state.north = false;
	state.south = false;
	state.west = false;
	state.east = false;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("Error"), false);
	if (!validate_texture_lines(fd, &state))
		return (close(fd), false);
	close(fd);
	if (!state.north || !state.south || !state.west || !state.east)
		return (ft_putstr_fd("Error\nTexture is missing\n", 2), false);
	return (true);
}
