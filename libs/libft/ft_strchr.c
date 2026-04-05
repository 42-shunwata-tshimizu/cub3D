/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:13:11 by tshimizu          #+#    #+#             */
/*   Updated: 2025/04/27 09:15:51 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Finds the first occurrence of a character in a string.
 *
 * Searches for the first occurrence
 * of the character `c` (converted to a `char`)
 * in the null-terminated string `s`.
 *
 * @param s The string to search in.
 * @param c The character to search for
 *(passed as an int, but internally treated as char).
 * @return A pointer to the first occurrence
 * of the character in the string,
 * or NULL if the character is not found.
 * If `c` is '\0', returns a pointer to the null terminator.
 *
 * ```` c
 *
 *  const char *str = "hello";
 *  char *result = ft_strchr(str, 'e');
 * // returns pointer to 'e';
 *  result = ft_strchr(str, 'x');
 * // returns NULL;
 * result = ft_strchr(str, '\0');
 * // returns pointer to '\0' at end of "hello";
 *
 * ````
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
