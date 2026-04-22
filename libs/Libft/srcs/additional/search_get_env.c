/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_get_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmasuda <nmasuda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 22:03:50 by shunwata          #+#    #+#             */
/*   Updated: 2026/02/28 21:35:53 by nmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "additional.h"

char	*search_get_env(char **ev, const char *search)
{
	int		i;
	size_t	len;

	if (!search)
		return (NULL);
	i = 0;
	len = ft_strlen(search);
	while (ev[i])
	{
		if (!ft_strncmp(ev[i], search, len))
		{
			if (ev[i][len] == '=')
				return (ev[i] + len + 1);
		}
		i++;
	}
	return (NULL);
}
