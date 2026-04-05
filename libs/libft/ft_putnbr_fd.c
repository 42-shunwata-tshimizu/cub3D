/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:34:14 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 13:21:41 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs an integer to the given file descriptor.
 *
 * The ft_putnbr_fd() function
 * writes the integer `n` to the file descriptor `fd`.
 * It handles negative numbers
 * by outputting a '-' sign and recursively processes
 * each digit of the number.
 *
 * @param n The integer to output.
 * @param fd The file descriptor on which to write. For example:
 *           - 0: Standard input
 *           - 1: Standard output
 *           - 2: Standard error
 *
 * @return None.
 *
 *
 * ```c
 *
 * ft_putnbr_fd(12345, 1); // Outputs "12345" to standard output.
 * ft_putnbr_fd(-6789, 1); // Outputs "-6789" to standard output.
 * ft_putnbr_fd(0, 1);     // Outputs "0" to standard output.
 *
 * ```
 */
void	ft_putnbr_fd(int n, int fd)
{
	if (n == INT_MIN)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}
