/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:16:21 by tshimizu          #+#    #+#             */
/*   Updated: 2025/04/26 22:02:46 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief checks whether c is a 7-bit
 * unsigned char value
 * that fits into the ASCII character set.
 *
 * @param c Target character to check
 * @return Non-zero value
 * if the character is an ASCII, 0 otherwise.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}
