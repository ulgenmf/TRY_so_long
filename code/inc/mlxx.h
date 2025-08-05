/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:54:25 by fuulgen           #+#    #+#             */
/*   Updated: 2025/08/05 14:55:52 by fuulgen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ESC_KEY 65307 // X11 keysym for ESC
typedef struct t_vec {
  int x;
  int y;
} t_vec;
typedef struct s_map {
  char **grid;
  t_vec size;
  t_vec player_loc;
  t_vec exit_loc;
  t_vec collectable_loc;
  int player_count;
  int exit_count;
  int collectible_count;
} t_map;

typedef struct s_textures {
  void *player;
  void *wall;
  void *floor;
  void *exit;
  void *collectible;
} t_textures;

typedef struct s_game {
  void *mlx;
  void *win;
  t_map *map;
  t_textures textures;

  int moves;
  int collected;
} t_game;
void get_locations(t_map *object);
void free_map(char **map);
void free_map_object(t_map *object);
void free_mlx_obj(t_game **obj);
int key_hook(int keycode, t_game *mlx_obj);
t_game *mlx_init_(t_map **map_obj);
void load_textures(t_game *game);
void draw_map(t_game *game);
