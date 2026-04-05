/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:09:30 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 15:23:40 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds a new node at the end of the linked list.
 *
 * The ft_lstadd_back() function adds the node `new` at the end
 * of the linked list pointed to by `lst`.
 *
 * @param lst A pointer to the pointer of the first node of the list.
 * @param new The new node to add at the end of the list.
 *
 * @return None.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}
