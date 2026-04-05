/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 09:39:35 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 10:18:32 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Applies a function
 *  to each character of a string to create a new string.
 *
 * The ft_strmapi() function applies the function `f` to each character of the
 * string `s` to create a new string (with `malloc`) resulting from successive
 * applications of `f`. The function `f` takes the index of the character as its
 * first argument and the character itself as its second argument.
 *
 * @param s The input string to be transformed.
 * @param f The function to apply to each character of the string.
 * @return A pointer to the newly allocated string resulting from the successive
 *         applications of `f`. Returns NULL if memory allocation fails or if
 *         `s` or `f` is NULL.
 *
 * @note The caller is responsible for freeing the memory allocated for the
 *       resulting string.
 *
 *
 * ```c
 *
 * char to_upper(unsigned int i, char c)
 * {
 *     (void)i;
 *     if (c >= 'a' && c <= 'z')
 *         return (c - 32);
 *     return (c);
 * }
 *
 * char *result = ft_strmapi("hello", to_upper);
 * printf("%s\n", result); // Output: "HELLO"
 * free(result);
 *
 * ```
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	result = malloc(ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
