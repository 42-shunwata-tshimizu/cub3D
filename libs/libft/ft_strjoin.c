/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:37:09 by tshimizu          #+#    #+#             */
/*   Updated: 2025/04/27 11:00:38 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_strjoin() function concatenates two strings into a new string.
 * It allocates memory for the resulting string and returns a pointer to it.
 *
 * If either `s1` or `s2` is NULL, the function returns NULL.
 * The resulting string is null-terminated.
 *
 * @param s1 The first string to concatenate.
 * @param s2 The second string to concatenate.
 * @return A pointer to the newly allocated string containing the concatenation
 *         of `s1` and `s2`. Returns NULL if memory allocation fails or if
 *         either `s1` or `s2` is NULL.
 *
 * @note The caller is responsible for freeing the memory allocated for the
 *       resulting string.
 * ```c
 *
 * char *result = ft_strjoin("Hello, ", "world!");
 * printf("%s\n", result); // Output: "Hello, world!"
 * free(result);
 *
 * ```
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	total_len = len1 + len2;
	result = (char *)malloc(total_len + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, len1);
	ft_memcpy(result + len1, s2, len2);
	result[total_len] = '\0';
	return (result);
}
