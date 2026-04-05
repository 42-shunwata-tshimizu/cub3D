/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:49:00 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 14:25:29 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates and initializes a new node for a linked list.
 *
 * The ft_lstnew() function allocates memory for a new node of type `t_list`
 * and initializes its `content` with the provided value. The `next` pointer
 * of the new node is set to `NULL`.
 *
 * @param content The content to initialize the new node with.
 *                This can be a pointer to any type of data.
 *
 * @return A pointer to the newly created node. Returns `NULL` if memory
 *         allocation fails.
 *
 * ```c
 *
 * t_list *node = ft_lstnew("Hello, world!");
 * if (node)
 * {
 *     printf("Content: %s\n", (char *)node->content);
 *     free(node);
 * }
 *
 * ```
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	if (!ret)
	{
		return (ret);
	}
	ret->content = content;
	ret->next = NULL;
	return (ret);
}
