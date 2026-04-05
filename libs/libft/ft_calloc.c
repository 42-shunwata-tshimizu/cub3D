/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:35:03 by tshimizu          #+#    #+#             */
/*   Updated: 2025/04/27 09:21:53 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The ft_calloc() function allocates memory
 * for an array of nmemb elements
 * of size bytes each and returns a pointer to the allocated memory.
 * The memory is set to zero.
 *
 * If nmemb or size is 0, then ft_calloc() returns either NULL,
 * or a unique pointer value that can be passed to free().
 *
 * If the multiplication of nmemb and size would
 * result in integer overflow,
 * ft_calloc() returns NULL.
 *
 * @param nmemb Number of elements to allocate.
 * @param size Size of each element.
 * @return On success, returns a pointer to the allocated memory,
 * which is zero-initialized.
 * On failure, returns NULL.
 *
 * ```c
 *  int *arr = (int *)ft_calloc(5, sizeof(int));
 *  if (arr == NULL)
 *  {
 *      // use arr
 *      free(arr);
 *  }
 * ```
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	res = malloc(nmemb * size);
	if (res)
		ft_bzero(res, nmemb * size);
	return (res);
}
