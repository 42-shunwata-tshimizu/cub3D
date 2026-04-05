/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:15:59 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 10:40:44 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs a string to the given file descriptor.
 *
 * The ft_putstr_fd() function writes
 * the string `s` to the file descriptor `fd`.
 *
 * @param s The string to output.
 * @param fd The file descriptor on which to write. For example:
 *           - 0: Standard input
 *           - 1: Standard output
 *           - 2: Standard error
 *
 * @return None.
 *
 * @note If `s` is NULL, the function does nothing.
 *
 *
 * ```c

 * ft_putstr_fd("Hello, world!", 1);
 *	// Outputs "Hello, world!" to standard output.
 * ft_putstr_fd("Error occurred.", 2);
 *	// Outputs "Error occurred." to standard error.
 * ```
 */
void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
