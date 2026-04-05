/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:36:29 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 16:26:04 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes and frees all nodes of a linked list.
 *
 * The ft_lstclear() function deletes and frees all nodes in the linked list
 * pointed to by `lst`.
 * The `del` function is used to free the content of each node.
 * The pointer to the list is set to `NULL` after all nodes are deleted.
 *
 * @param lst A pointer to the pointer of the first node of the list.
 * @param del A function to free the content of each node.
 *
 * @return None.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
