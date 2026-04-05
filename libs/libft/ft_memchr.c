/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:34:00 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 11:47:20 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_memchr() function scans the initial n bytes of the memory area
 * pointed to by s for the first instance of c. Both c and the bytes of the
 * memory area pointed to by s are interpreted as unsigned char.
 *
 * @param s Memory area to be searched (pointer).
 * @param c Value to be searched (range from 0 to 255, cast to unsigned char).
 * @param n Number of bytes to examine (size_t type).
 * @return A pointer to the matching byte or
 * NULL if the character does not occur
 * in the given memory area.
 *
 * @example
 * ```c
 * char data[] = "hello";
 * char *result = ft_memchr(data, 'e', 5); // returns pointer to 'e'
 * result = ft_memchr(data, 'a', 5);       // returns NULL
 * ```
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (NULL);
}
