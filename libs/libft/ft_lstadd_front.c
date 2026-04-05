/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:23:35 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 14:43:17 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds a new node at the beginning of the linked list.
 *
 * The ft_lstadd_front() function adds the node `new` at the beginning
 * of the linked list pointed to by `lst`.
 *
 * @param lst A pointer to the pointer of the first node of the list.
 * @param new The new node to add at the beginning of the list.
 *
 * @return None.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
