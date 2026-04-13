/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:19:05 by tshimizu          #+#    #+#             */
/*   Updated: 2026/04/10 00:51:41 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "../libs/libft/libft.h"
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

bool	validate_argv(int ac, char *av[]);
bool	validate_texture(char **lines);

#endif // VALIDATION_H
