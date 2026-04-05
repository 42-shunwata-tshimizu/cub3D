/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:38:32 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 10:17:48 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs a character to the given file descriptor.
 *
 * The ft_putchar_fd() function
 * writes the character `c` to the file descriptor `fd`.
 *
 * @param c The character to output.
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
 * ft_putchar_fd('A', 1); // Outputs 'A' to the standard output.
 * ft_putchar_fd('\n', 1); // Outputs a newline to the standard output.

 * ```
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
