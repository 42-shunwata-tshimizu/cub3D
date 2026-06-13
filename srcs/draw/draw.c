/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 11:27:14 by tshimizu          #+#    #+#             */
/*   Updated: 2026/06/13 17:39:01 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	put_pixel(t_image *image, int x, int y, int color)
{
	char	*dst;
	int		offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = y * image->line_length + x * (image->bpp / 8);
	dst = image->addr + offset;
	*(unsigned int *)dst = (unsigned int)color;
}

static int	get_texture_color(const t_texture *texture, int tex_x, int tex_y)
{
	char			*dst;
	unsigned char	*pixel;

	if (tex_x < 0 || tex_x >= texture->width || tex_y < 0
		|| tex_y >= texture->height)
		return (0x000000);
	dst = texture->addr + tex_y * texture->line_length
		+ tex_x * (texture->bpp / 8);
	pixel = (unsigned char *)dst;
	return ((pixel[2] << 16) | (pixel[1] << 8) | pixel[0]);
}

static const t_texture	*get_wall_texture(const t_game *game, int face)
{
	if (face == WALL_NORTH)
		return (&game->textures.north);
	if (face == WALL_SOUTH)
		return (&game->textures.south);
	if (face == WALL_WEST)
		return (&game->textures.west);
	return (&game->textures.east);
}

static void	draw_wall_strip(t_game *game, int screen_x, const t_ray *ray)
{
	const t_texture	*texture;
	int				line_height;
	int				y;
	int				tex_x;

	texture = get_wall_texture(game, ray->face);
	line_height = (int)(HEIGHT / ray->wall_dist);
	if (line_height > HEIGHT * 4)
		line_height = HEIGHT * 4;
	y = HEIGHT / 2 - line_height / 2;
	if (y < 0)
		y = 0;
	tex_x = (int)(ray->wall_hit_pos * (double)texture->width);
	while (y < HEIGHT / 2 + line_height / 2 && y < HEIGHT)
	{
		put_pixel(&game->image, screen_x, y,
			get_texture_color(
				texture,
				tex_x,
				(int)((y - (HEIGHT / 2 - line_height / 2))
					* texture->height / line_height)));
		y++;
	}
}

void	render_frame(t_game *game)
{
	int		x;
	int		y;
	t_ray	ray;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y < HEIGHT / 2)
				put_pixel(&game->image, x, y, game->map->ceiling_color);
			else
				put_pixel(&game->image, x, y, game->map->floor_color);
		}
	}
	x = -1;
	while (++x < WIDTH)
	{
		ray = cast_ray(game, x);
		draw_wall_strip(game, x, &ray);
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->image.img, 0, 0);
}
