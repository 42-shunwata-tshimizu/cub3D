/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 22:09:37 by shunwata          #+#    #+#             */
/*   Updated: 2025/12/23 17:11:29 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "additional.h"

bool	ft_replace(char **origin, const char *repl, size_t strt, size_t l)
{
	char	*new_str;
	size_t	new_len;

	if (!origin || !*origin || !repl)
		return (false);
	new_len = ft_strlen(*origin) - l + ft_strlen(repl);
	new_str = ft_calloc(new_len + 1, sizeof(char));
	if (!new_str)
		return (false);
	ft_strlcpy(new_str, *origin, strt + 1);
	ft_strlcat(new_str, repl, new_len + 1);
	ft_strlcat(new_str, *origin + strt + l, new_len + 1);
	free(*origin);
	*origin = new_str;
	return (true);
}
