/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:37:46 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 10:56:38 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/**
 * @brief Converts an integer to a null-terminated string.
 *
 * The ft_itoa() function takes an integer `n` and converts it into a
 * dynamically allocated null-terminated string representation of the number.
 *
 * @param n The integer to be converted.
 * @return A pointer to the newly allocated string representing the integer.
 *         Returns NULL if memory allocation fails.
 *
 * @note The caller is responsible for freeing the memory allocated for the
 *       resulting string.
 *
 * ```c
 *
 * char *str = ft_itoa(12345);
 * printf("%s\n", str); // Output: "12345"
 * free(str);
 *
 * str = ft_itoa(-6789);
 * printf("%s\n", str); // Output: "-6789"
 * free(str);
 *
 * str = ft_itoa(0);
 * printf("%s\n", str); // Output: "0"
 * free(str);
 *
 * ```
 */
char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nb;

	nb = n;
	len = ft_numlen(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		str[0] = '0';
	while (nb)
	{
		str[--len] = '0' + (nb % 10);
		nb /= 10;
	}
	return (str);
}
