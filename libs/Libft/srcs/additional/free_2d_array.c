/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2d_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 22:11:27 by shunwata          #+#    #+#             */
/*   Updated: 2026/02/09 22:11:53 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "additional.h"

void	free_2d_array(char ***array)
{
	size_t	i;

	if (!array || !*array)
		return ;
	i = 0;
	while ((*array)[i])
	{
		free((*array)[i]);
		(*array)[i] = NULL;
		i++;
	}
	free(*array);
	*array = NULL;
}
