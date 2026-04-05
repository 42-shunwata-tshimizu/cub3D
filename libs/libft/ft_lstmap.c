/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:03:06 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 16:45:31 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Creates a new list by applying a function to each node's content.
 *
 * The ft_lstmap() function iterates through the linked list `lst` and applies
 * the function `f` to the content of each node. A new list is created with
 * the results of the function `f`. If memory allocation fails, the `del`
 * function is used to free the content of the nodes.
 *
 * @param lst A pointer to the first node of the list.
 * @param f A function to apply to the content of each node.
 * @param del A function to free the content of a node in case of failure.
 * @return A pointer to the first node of the new list,
 *  or NULL if allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			if (new_content)
				del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
