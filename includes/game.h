/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:16:04 by tshimizu          #+#    #+#             */
/*   Updated: 2026/05/23 14:26:04 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# define NOT_FOUND -1
# define WIDTH 1280
# define HEIGHT 720

# include <stdbool.h>
# include <stdlib.h>

typedef enum e_key_mask
{
	KEY_PRESS_MASK = (1L << 0),
	KEY_RELEASE_MASK = (1L << 1),
	CLOSE_WINDOW_MASK = 0
}				t_key_mask;

typedef enum e_key_event
{
	KEY_PRESS = 2,
	KEY_RELEASE = 3,
	CLOSE_WINDOW = 17,
}				t_key_event;

typedef enum e_key_codes
{
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	KEY_ESC = 65307,
}				t_key_codes;

typedef struct s_keys
{
	bool		key_w;
	bool		key_a;
	bool		key_s;
	bool		key_d;
	bool		key_left;
	bool		key_right;
	bool		key_esc;
}				t_keys;

typedef struct s_map
{
	int			width;
	int			height;
	char		**map_data;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;

	int			floor_color;
	int			ceiling_color;
}				t_map;

typedef struct s_player
{
	int			position_x;
	int			position_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_map		*map;
	t_player	*player;
	t_keys		*keys;
}				t_game;

#endif // GAME_H
