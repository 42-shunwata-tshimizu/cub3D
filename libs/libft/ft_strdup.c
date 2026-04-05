/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:46:59 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 10:47:03 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_strdup() function duplicates the given null-terminated string s
 * by allocating sufficient memory for a copy, and returns a pointer to it.
 *
 * Memory for the new string is obtained with malloc,
 * and can be freed with free().
 *
 * If insufficient memory is available, NULL is returned.
 *
 * @param s The null-terminated string to duplicate.
 * @return On success, returns a pointer to the duplicated string.
 *         On failure, returns NULL.
 *
 * ```c
 *
 *  char *copy = ft_strdup("hello");
 *  if (copy != NULL)
 *  {
 *      printf("%s\n", copy); // prints "hello"
 *      free(copy);
 *  }
 *
 * ```
 */
char	*ft_strdup(const char *s)
{
	int		len;
	char	*duplicate;
	char	*answer;

	len = ft_strlen(s);
	duplicate = (char *)malloc(len + 1);
	if (duplicate == NULL)
		return (NULL);
	answer = duplicate;
	while (*s)
	{
		*duplicate = *s;
		s++;
		duplicate++;
	}
	*duplicate = '\0';
	return (answer);
}
