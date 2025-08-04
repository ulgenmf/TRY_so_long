/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 10:54:25 by fuulgen           #+#    #+#             */
/*   Updated: 2025/08/04 11:54:12 by fuulgen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_game {
  void *mlx;
  void *win;
  t_map map;

  int moves;
  int collected;
} t_game;
typedef struct s_textures {
  void *player;
  void *wall;
  void *floor;
  void *exit;
  void *collectible;
} t_textures;
void get_locations(t_map *object);
void free_map(char **map);
void free_map_object(t_map *object);
void free_mlx_obj(t_game *obj);
t_game *mlx_init_(t_map *map_obj);
