/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:34:34 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 11:34:16 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_strnstr() function locates
 * the first occurrence of the null-terminated string
 * little in the string big,
 * where not more than len characters are searched.
 * Characters that appear
 * after a `\0` character are not searched.
 *
 * @param big The larger string to be searched.
 * @param little The smaller string to find within big.
 * @param len The maximum number of characters to search.
 * @return (If little is an empty string, big is returned);
 * if little occurs nowhere in big, NULL is returned;
 * otherwise a pointer to
 * the first character of the first occurrence of little is returned.
 *
 * ```c
 *
 *  ft_strnstr("Hello, world", "world", 12); // returns pointer to "world"
 *  ft_strnstr("Hello, world", "planet", 12); // returns NULL
 *  ft_strnstr("Hello", "", 5); // returns pointer to "Hello"
 *
 * ```
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	big_len;
	size_t	i;

	if (*little == '\0')
		return ((char *)big);
	little_len = ft_strlen(little);
	big_len = ft_strlen(big);
	if (little_len > len || little_len > big_len)
		return (NULL);
	if (len > big_len)
		len = big_len;
	i = 0;
	while (i <= len - little_len)
	{
		if (big[i] == little[0] && ft_strncmp(&big[i + 1], &little[1],
				little_len - 1) == 0)
		{
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
