/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:35:33 by tshimizu          #+#    #+#             */
/*   Updated: 2025/04/27 10:23:06 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_substr() function allocates and returns a substring
 *        from the string 's'. The substring begins at index 'start'
 *        and is of maximum length 'len'.
 *
 * If 'start' is greater than the length of 's', the function returns
 * an allocated empty string ("").
 * If 'len' extends past the end of 's', it adjusts 'len' to fit within 's'.
 *
 * @param s The source string.
 * @param start The start index of the substring.
 * @param len The maximum length of the substring.
 * @return A pointer to the newly allocated substring.
 *         Returns NULL if the allocation fails or if 's' is NULL.
 *
 * ```c
 *  ft_substr("Hello, world", 7, 5);  // returns "world"
 *  ft_substr("Hello", 10, 3);         // returns ""
 * ```
 */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
