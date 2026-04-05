/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:15:03 by tshimizu          #+#    #+#             */
/*   Updated: 2025/04/26 22:04:56 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_strlen()
 * function calculates the length of the string pointed to by s,
 * excluding the terminating null byte ('\0').
 *
 * @param *s Target pointer to the string.
 * @return The ft_strlen() function returns
 * the number of bytes in the string pointed to by s.
 */
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s += 1;
	}
	return (len);
}
