/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:19:05 by tshimizu          #+#    #+#             */
/*   Updated: 2026/05/17 11:14:18 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "libft.h"
# include "utils.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_texture_state
{
	bool	north;
	bool	south;
	bool	west;
	bool	east;
}			t_texture_state;

typedef struct s_color_state
{
	bool	floor;
	bool	ceiling;
}			t_color_state;

bool	validate_argv(int ac, char *av[]);
bool	validate_texture(char **lines);
bool	validate_color(char **lines);

#endif // VALIDATION_H
