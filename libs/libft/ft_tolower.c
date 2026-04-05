/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:33:13 by tshimizu          #+#    #+#             */
/*   Updated: 2025/04/26 22:10:47 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts an uppercase letter to its lowercase equivalent.
 *
 * If the input character is an uppercase letter ('A' to 'Z'),
 * it will be converted to the corresponding lowercase letter ('a' to 'z').
 * If the input character is not an uppercase letter, it is returned unchanged.
 *
 * @param c The character to convert.
 * @return The lowercase equivalent if c is an uppercase letter;
 *         otherwise, returns c unchanged.
 *
 * @code
 *  ft_tolower('A'); // returns 'a'
 *  ft_tolower('a'); // returns 'a'
 *  ft_tolower('1'); // returns '1'
 * @endcode
 */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
