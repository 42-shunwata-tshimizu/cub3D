/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:53:55 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 16:30:46 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Iterates through a linked list and
 * applies a function to each node's content.
 *
 * The ft_lstiter() function iterates through the linked list `lst` and applies
 * the function `f` to the content of each node.
 *
 * @param lst A pointer to the first node of the list.
 * @param f A function to apply to the content of each node.
 *
 * @return None.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
