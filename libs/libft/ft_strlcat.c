/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:15:22 by tshimizu          #+#    #+#             */
/*   Updated: 2025/04/26 22:10:03 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Appends src to string dst of size dsize
 *(unlike strncat, dsize is the full size of dst, not space left).
 *
 * It will append at most dsize - strlen(dst) - 1 bytes,
 * null-terminating the result (as long as dsize is larger than strlen(dst)).
 *
 * @param dst Pointer to the destination string buffer.
 * Must be null-terminated.
 * @param src Pointer to the source string to append.
 * @param dsize Total size of the destination buffer.
 *
 * @return The total length of the string it tried to create
 * (initial length of dst + length of src).
 * If the return value is >= dsize, truncation occurred.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	src_len = ft_strlen(src);
	while (dst_len < dstsize && dst[dst_len])
		dst_len++;
	if (dst_len < dstsize)
	{
		i = 0;
		while ((dst_len + i + 1) < dstsize && src[i])
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		if ((dst_len + i) < dstsize)
			dst[dst_len + i] = '\0';
	}
	return (dst_len + src_len);
}
