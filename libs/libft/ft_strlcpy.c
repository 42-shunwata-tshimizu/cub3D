/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:15:14 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 12:29:50 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Safely copies a null-terminated
 * string from src to dst with size limit.
 *
 * Copies up to dsize - 1 characters from the string src to dst,
 * null-terminating the result if dsize is not 0.
 *
 * @param[out] dst  Pointer to the destination buffer
 * where the string will be copied.
 * @param[in]  src  Pointer to the null-terminated
 * source string to copy from.
 * @param[in]  dsize Size of the destination buffer,
 * including space for the null terminator.
 *
 * @return The total length of the source string
 * (not including the null terminator).
 * If the return value is >= dsize, truncation occurred.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;

	i = 0;
	if (dsize != 0)
	{
		while (src[i] && i < dsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
