/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 09:25:49 by tshimizu          #+#    #+#             */
/*   Updated: 2025/04/27 09:26:15 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_atoi() function converts the initial portion of the string
 * pointed to by nptr to int. The function first discards any whitespace
 * characters until the first non-whitespace character is found. Then it
 * takes an optional '+' or '-' sign followed by as many numerical digits
 * as possible, and interprets them as a numerical value.
 *
 * @param nptr Pointer to the null-terminated string to convert.
 * @return The converted integer value.
 * If no valid conversion could be performed, returns 0.
 *
 * ```c
 *
 *  ft_atoi("42");       // returns 42
 *  ft_atoi("   -42");   // returns -42
 *  ft_atoi("4193abc");  // returns 4193
 *  ft_atoi("abc123");   // returns 0
 *
 * ```
 */
int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

// #include <stdlib.h>

// int main()
// {
// 	char test[] =" 	-123467890ab567";
// 	printf("ft_atoi is");
// 	printf("%d",ft_atoi(test));
// 	printf("\n");
// 	printf("atoi is");
// 	printf("%d",atoi(test));
// 	return (0);
// }
