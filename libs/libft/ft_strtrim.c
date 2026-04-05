/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:48:20 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 10:48:24 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Trims characters from the beginning and end of a string.
 *
 * The ft_strtrim() function removes all characters in the string `set`
 * from the beginning and end of the string `s1`. The resulting string
 * is allocated dynamically and must be freed by the caller.
 *
 * @param s1 The string to be trimmed.
 * @param set The set of characters to remove.
 * @return A newly allocated trimmed string, or NULL if allocation fails
 *         or if `s1` or `set` is NULL.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
}
