/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:19:05 by tshimizu          #+#    #+#             */
/*   Updated: 2026/04/06 22:19:05 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include <stdbool.h>
#include <fcntl.h>
#include <stdio.h>
#include "../libs/libft/libft.h"


bool validate_argv(int ac,char *av[]);
#endif // VALIDATION_H
