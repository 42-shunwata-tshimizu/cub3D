/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:45:33 by shunwata          #+#    #+#             */
/*   Updated: 2025/12/22 20:31:32 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "additional.h"

size_t	ft_strnlen(const char *s, size_t n)
{
	const char	*h = s;

	while (n && *s)
		(void)(n--, s++);
	return (s - h);
}
