/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:33:47 by tshimizu          #+#    #+#             */
/*   Updated: 2025/04/27 09:17:49 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares two strings up to n characters.
 *
 * Compares the first n bytes of the strings s1 and s2.
 * The comparison is done using unsigned characters.
 *
 * @param s1 First string to compare.
 * @param s2 Second string to compare.
 * @param n Maximum number of characters to compare.
 * @return An integer less than, equal to,
 * or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 *
 * ```c
 *
 *  ft_strncmp("abc", "abd", 2); // returns 0;
 *  ft_strncmp("abc", "abd", 3); // returns negative value;
 *  ft_strncmp("abc", "abc", 3); // returns 0;
 *
 * ```
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2)
		{
			return ((int)((unsigned char)*s1 - (unsigned char)*s2));
		}
		if (*s1 == '\0' || *s2 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (0);
}
