/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 17:12:48 by shunwata          #+#    #+#             */
/*   Updated: 2026/05/30 17:13:02 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec2
{
	double	x;
	double	y;
}				t_vec2;

typedef struct s_coordinate
{
	double	x;
	double	y;
}				t_coordinate;

t_vec2			vec2(double x, double y);
t_vec2			vec2_add(t_vec2 a, t_vec2 b);
t_vec2			vec2_scale(t_vec2 vec, double scalar);
t_vec2			vec2_perpendicular(t_vec2 vec);

#endif // VECTOR_H
