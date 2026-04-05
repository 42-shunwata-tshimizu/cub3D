/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:47:36 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 10:51:21 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Finds the last occurrence of a character in a string.
 *
 * Searches for the last occurrence of the character `c` (converted to a `char`)
 * in the null-terminated string `s`.
 *
 * @param s The string to search in.
 * @param c The character to search for.
 * @return A pointer to the last occurrence of the character in the string,
 *         or NULL if the character is not found.
 *         If `c` is '\0', returns a pointer to the null terminator.
 *
 * ```c
 *
 * const char *str = "hello";
 * char *result = ft_strrchr(str, 'l');
 * // returns pointer to the second 'l';
 * result = ft_strrchr(str, 'h');
 * // returns pointer to 'h';
 * result = ft_strrchr(str, 'x');
 * // returns NULL;
 * result = ft_strrchr(str, '\0');
 * // returns pointer to '\0' at end of "hello";
 *
 * ```
 */
char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (1)
	{
		if (s[len] == (char)c)
			return ((char *)(s + len));
		if (len == 0)
			break ;
		len--;
	}
	return (NULL);
}
