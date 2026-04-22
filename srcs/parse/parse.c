/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:55:29 by shunwata          #+#    #+#             */
/*   Updated: 2026/04/13 17:55:32 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

bool	parse(char **lines)
{
	if (!validate_texture(lines))
		return (false);
	return (true);
}
