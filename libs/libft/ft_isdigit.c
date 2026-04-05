/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:16:08 by tshimizu          #+#    #+#             */
/*   Updated: 2025/04/26 22:01:08 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief checks for a digit (0 through 9).
 *
 * @param c Target number to check
 * @return Non-zero value
 * if the character is an digit (1-9), 0 otherwise.
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
