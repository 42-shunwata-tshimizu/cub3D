/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:19:05 by tshimizu          #+#    #+#             */
/*   Updated: 2026/04/07 23:34:59 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "../libs/libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

bool	validate_argv(int ac, char *av[]);
#endif // VALIDATION_H
