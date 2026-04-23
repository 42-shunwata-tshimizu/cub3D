/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:39:12 by nmasuda           #+#    #+#             */
/*   Updated: 2026/02/09 22:08:53 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "additional.h"

static void	skip_spaces(const char **s)
{
	while (**s == ' ' || (**s >= 9 && **s <= 13))
		(*s)++;
}

static bool	check_overflow(unsigned long long res, int next_digit, int sign)
{
	unsigned long long	cutoff;
	int					cutlim;

	cutoff = LLONG_MAX / 10;
	cutlim = LLONG_MAX % 10;
	if (sign == -1)
		cutlim += 1;
	if (res > cutoff)
		return (true);
	if (res == cutoff && next_digit > cutlim)
		return (true);
	return (false);
}

long long	set_error_flag(bool *error)
{
	*error = true;
	return (1);
}

long long	ft_atol(const char *str, bool *error)
{
	unsigned long long	res;
	int					sign;

	res = 0;
	sign = 1;
	skip_spaces(&str);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!(*str >= '0' && *str <= '9'))
		return (set_error_flag(error));
	while (*str >= '0' && *str <= '9')
	{
		if (check_overflow(res, *str - '0', sign))
			return (set_error_flag(error));
		res = res * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0')
		return (set_error_flag(error));
	return ((long long)(res * sign));
}
