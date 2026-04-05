/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:37:37 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 10:49:28 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_charset(char c, char charset)
{
	return (c == charset);
}

static int	count_words(const char *str, char charset)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (is_in_charset(*str, charset))
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static char	*next_word(const char **s, char charset)
{
	const char	*start;
	int			len;

	while (**s && is_in_charset(**s, charset))
		(*s)++;
	start = *s;
	len = 0;
	while ((*s)[len] && !is_in_charset((*s)[len], charset))
		len++;
	*s += len;
	return (ft_substr(start, 0, len));
}

/**
 * @brief Splits a string into an array of substrings based on a delimiter.
 *
 * The ft_split() function takes a string `s` and splits it into an array of
 * substrings, using the character `c` as the delimiter. The resulting array
 * is dynamically allocated and must be freed by the caller.
 *
 * Consecutive delimiters are treated as a single delimiter,
 * and empty substrings
 * are not included in the result.
 *
 * @param s The input string to be split.
 * @param c The delimiter character used to split the string.
 * @return A NULL-terminated array of substrings. Returns NULL if memory
 *         allocation fails or if `s` is NULL.
 *
 * @note The caller is responsible for freeing the memory allocated for the
 *       resulting array and its substrings.
 *
 * ```c
 *
 * char **result = ft_split("hello  world! this is a test", ' ');
 * for (int i = 0; result[i]; i++)
 * {
 *     printf("[%s]\n", result[i]);
 *     free(result[i]);
 * }
 * free(result);
 * // Output:
 * // [hello]
 * // [world!]
 * // [this]
 * // [is]
 * // [a]
 * // [test]
 *
 * ```
 */
char	**ft_split(const char *s, char c)
{
	char	**result;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < words)
	{
		result[i] = next_word(&s, c);
		if (!result[i])
		{
			while (--i >= 0)
				free(result[i]);
			free(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	**split;

// 	split = ft_split("hello  world! this is a test", ' ');
// 	for (int i = 0; split[i]; i++)
// 	{
// 		printf("[%s]\n", split[i]);
// 		free(split[i]);
// 	}
// 	free(split);
// 	return (0);
// }
