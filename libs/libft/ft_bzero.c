/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:17:20 by tshimizu          #+#    #+#             */
/*   Updated: 2025/04/26 22:06:41 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The  bzero() function erases the data in the n bytes
 * of the memory starting at the location
 * pointed to by s, by writing zeros  (bytescontaining '\0')
 * to that area.The explicit_bzero()
 * function performs the same task as bzero().
 * It differs from bzero() in that it guarantees that compiler
 * opti‐mizations  will not remove the erase operation
 * if the compiler de‐duces that the operation is "unnecessary".
 *
 * @param *s Memory area to be initialized (pointer)
 * @param n Number of bytes (size_t type)
 * @return (None);
 */
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		tmp[i] = (unsigned char)0;
		i++;
	}
}
