/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:32:14 by tshimizu          #+#    #+#             */
/*   Updated: 2025/04/26 22:10:29 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts a lowercase letter to its uppercase equivalent.
 *
 * If the input character is a lowercase letter ('a' to 'z'),
 * it will be converted to the corresponding uppercase letter ('A' to 'Z').
 * If the input character is not a lowercase letter, it is returned unchanged.
 *
 * @param c The character to convert.
 * @return (The uppercase equivalent if c is a lowercase letter);
 *         otherwise, returns c unchanged.
 *
 * @code
 *  ft_toupper('a'); // returns 'A'
 *  ft_toupper('A'); // returns 'A'
 *  ft_toupper('1'); // returns '1'
 * @endcode
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
