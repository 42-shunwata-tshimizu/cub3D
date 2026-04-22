/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 20:06:46 by shunwata          #+#    #+#             */
/*   Updated: 2026/02/09 22:12:14 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDITIONAL_H
# define ADDITIONAL_H

# include <stdbool.h>
# include <limits.h>
# include "libft.h"

void		free_2d_array(char ***array);
long long	ft_atol(const char *str, bool *error);
bool		ft_replace(char **origin, const char *repl, size_t strt, size_t l);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strndup(const char *s1, size_t n);
size_t		ft_strnlen(const char *s, size_t n);
char		*search_get_env(char **ev, const char *search);

#endif
