/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:51:36 by shunwata          #+#    #+#             */
/*   Updated: 2026/04/13 17:59:34 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

char	*skip_space(const char *line)
{
	while (*line && is_space(*line))
		line++;
	return ((char *)line);
}
