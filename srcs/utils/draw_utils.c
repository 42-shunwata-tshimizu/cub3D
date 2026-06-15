/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 19:58:37 by shunwata          #+#    #+#             */
/*   Updated: 2026/06/15 19:59:07 by shunwata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	put_pixel(t_image *image, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = y * image->line_length + x * (image->bpp / 8);
	dst = image->addr + offset;
	*(unsigned int *)dst = (unsigned int)color;
}

int	get_wall_top(int line_height)
{
	return (HEIGHT / 2 - line_height / 2);
}

int	get_wall_bottom(int line_height)
{
	return (HEIGHT / 2 + line_height / 2);
}

int	get_tex_y(int y, int line_height, int texture_height)
{
	int	wall_top;

	wall_top = get_wall_top(line_height);
	return ((y - wall_top) * texture_height / line_height);
}
