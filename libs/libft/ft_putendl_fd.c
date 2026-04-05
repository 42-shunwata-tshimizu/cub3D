/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:39:01 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 10:32:26 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs a string to the given file descriptor,
 * followed by a newline.
 *
 * The ft_putendl_fd() function
 * writes the string `s` to the file descriptor `fd`,
 * followed by a newline character (`\n`).
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
 *
 * ft_putendl_fd("Hello, world!", 1); // Outputs "Hello, world!\n"
 * to standard output.
 * ft_putendl_fd("Error occurred.", 2); // Outputs "Error occurred.\n"
 * to standard error.
 *
 * ```
 */
void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	ft_putchar_fd('\n', fd);
}
