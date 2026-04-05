/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:06:10 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 15:08:29 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the last node of the linked list.
 *
 * The ft_lstlast() function iterates through the linked list
 * and returns a pointer to the last node.
 *
 * @param lst A pointer to the first node of the list.
 * @return A pointer to the last node of the list, or NULL if the list is empty.
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
