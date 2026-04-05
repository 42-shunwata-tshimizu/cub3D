/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:34:14 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 10:56:00 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_memcmp() function compares
 * the first n bytes (each interpreted as unsigned char)
 * of the memory areas s1 and s2.
 *
 * @param s1 First memory area to compare (pointer).
 * @param s2 Second memory area to compare (pointer).
 * @param n Maximum number of bytes to compare (size_t type).
 * @return An integer less than, equal to, or
 * greater than zero if the first n bytes of s1
 * is found to be less than, to match,
 * or be greater than those of s2 respectively.
 *
 * ```c
 *
 *  char a[] = "abc";
 *  char b[] = "abc";
 *  char c[] = "abd";
 *
 *  ft_memcmp(a, b, 3); // returns 0
 *  ft_memcmp(a, c, 3); // returns negative value
 *  ft_memcmp(c, a, 3); // returns positive value
 *
 * ```
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n--)
	{
		if (*str1 != *str2)
			return ((int)(*str1 - *str2));
		str1++;
		str2++;
	}
	return (0);
}
