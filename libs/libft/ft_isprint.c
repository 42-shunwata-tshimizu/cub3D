/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:16:01 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 11:47:12 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief checks for any printable character including space.
 *
 * @param c Target character to check
 * @return Non-zero value
 * if the character is an printable character
 * including space, 0 otherwise.
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
