/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:17:11 by tshimizu          #+#    #+#             */
/*   Updated: 2025/04/26 22:01:57 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief checks for a alphanumeric character;
 * it is equivalent to(isalpha(c)||isdigit(c)).
 *
 * @param c Target character to check
 * @return Non-zero value
 * if the character is an digit or alphabet
 * (1-9 or A-Z or a-z), 0 otherwise.
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
