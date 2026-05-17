/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 11:54:32 by shunwata          #+#    #+#             */
/*   Updated: 2026/05/17 11:14:24 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "validation.h"

static bool	validate_rgb_value(char **line)
{
	int	result;
	int	digits;

	*line = skip_space(*line);
	result = 0;
	digits = 0;
	while (ft_isdigit(**line))
	{
		result = result * 10 + (**line - '0');
		if (result > 255)
			return (false);
		(*line)++;
		digits++;
	}
	return (digits != 0);
}

static bool	validate_rgb(char *line)
{
	line = skip_space(line + 1);
	if (!validate_rgb_value(&line) || *line++ != ',')
		return (ft_putstr_fd("Error\nInvalid color\n", 2), false);
	if (!validate_rgb_value(&line) || *line++ != ',')
		return (ft_putstr_fd("Error\nInvalid color\n", 2), false);
	if (!validate_rgb_value(&line))
		return (ft_putstr_fd("Error\nInvalid color\n", 2), false);
	line = skip_space(line);
	if (*line != '\0')
		return (ft_putstr_fd("Error\nInvalid color\n", 2), false);
	return (true);
}

static bool	register_color(char *line, t_color_state *state)
{
	if (line[0] == 'F' && is_space(line[1]) && state->floor)
		return (ft_putstr_fd("Error\nDuplicate floor color\n", 2), false);
	if (line[0] == 'C' && is_space(line[1]) && state->ceiling)
		return (ft_putstr_fd("Error\nDuplicate ceiling color\n", 2), false);
	if (line[0] == 'F' && is_space(line[1]))
	{
		state->floor = true;
		return (validate_rgb(line));
	}
	if (line[0] == 'C' && is_space(line[1]))
	{
		state->ceiling = true;
		return (validate_rgb(line));
	}
	return (true);
}

bool	validate_color(char **lines)
{
	t_color_state	state;
	int				i;

	ft_bzero(&state, sizeof(t_color_state));
	i = 0;
	while (lines[i])
	{
		if (!register_color(skip_space(lines[i]), &state))
			return (false);
		i++;
	}
	if (!state.floor || !state.ceiling)
		return (ft_putstr_fd("Error\nColor is missing\n", 2), false);
	return (true);
}
