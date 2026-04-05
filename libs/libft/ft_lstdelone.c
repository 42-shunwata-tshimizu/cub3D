/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:27:04 by tshimizu          #+#    #+#             */
/*   Updated: 2025/05/04 16:27:07 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Deletes a single node from a linked list.
 *
 * The ft_lstdelone() function deletes the given node `lst` by using the
 * function `del` to free the content of the node,
 *  and then frees the node itself.
 *
 * @param lst The node to delete.
 * @param del A function to free the content of the node.
 *
 * @return None.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
