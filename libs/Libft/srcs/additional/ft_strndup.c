/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:50:02 by shunwata          #+#    #+#             */
/*   Updated: 2025/12/22 20:31:20 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "additional.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	size;
	char	*result;

	size = ft_strnlen(s1, n) + 1;
	result = (char *)malloc(size);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, size);
	return (result);
}
