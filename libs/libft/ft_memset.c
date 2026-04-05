/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:15:34 by tshimizu          #+#    #+#             */
/*   Updated: 2025/04/26 22:05:26 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The memset() function
 * fills the first n bytes of the memory area
 * pointed to by s with the constant byte c.
 *
 * @param s Memory area to be initialized (pointer)
 * @param c Value to be set (range from 0 to 255, cast to unsigned char)
 * @param n Number of bytes (size_t type)
 * @return The ft_memset() function returns a pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		tmp[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
