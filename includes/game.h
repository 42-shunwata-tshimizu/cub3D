/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimizu <tshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 22:16:04 by tshimizu          #+#    #+#             */
/*   Updated: 2026/04/19 20:13:45 by tshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_map
{
	int		width;
	int		height;
	char	**map_data;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;

    int floor_color;
    int ceiling_color;
}			t_map;


typedef struct s_player
{
	int	position_x;
	int	position_y;

}		t_player;

typedef struct s_game
{
    void *mlx;
    void *mlx_win;
    t_map *map;
    t_player *player;
} t_game;

#endif // GAME_H
