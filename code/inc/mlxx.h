/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:54:25 by fuulgen           #+#    #+#             */
/*   Updated: 2025/07/28 10:55:36 by fuulgen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


typedef struct t_vector{
	int x;

	int y;
}
t_vector;
typedef struct s_player
{
	t_vector pos;
    t_vector pixel;
} t_player;

typedef struct s_textures {
    void        *wall;
    void        *floor;
    void        *player;
    void        *collectible;
    void        *exit;
    t_vector    size;
} t_textures;

typedef struct s_game {
    void        *mlx;
    void        *win;
    char        **map;
    t_player    player;
    t_textures  textures;
    t_vector    map_size;
    int         collectibles;
    int         collected;
    int         moves;
    int         game_won;
} t_game;
