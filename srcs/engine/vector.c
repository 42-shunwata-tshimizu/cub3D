/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:14:13 by shunwata          #+#    #+#             */
/*   Updated: 2026/05/30 17:14:15 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2	vec2(double x, double y)
{
	t_vec2	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

t_vec2	vec2_add(t_vec2 a, t_vec2 b)
{
	return (vec2(a.x + b.x, a.y + b.y));
}

t_vec2	vec2_scale(t_vec2 vec, double scalar)
{
	return (vec2(vec.x * scalar, vec.y * scalar));
}

t_vec2	vec2_perpendicular(t_vec2 vec)
{
	return (vec2(-vec.y, vec.x));
}
