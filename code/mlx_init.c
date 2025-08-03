// /* **************************************************************************
// */
// /* */
// /*                                                        :::      ::::::::
// */
// /*   mlx_init.c                                         :+:      :+:    :+:
// */
// /*                                                    +:+ +:+         +:+ */
// /*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+ */
// /*                                                +#+#+#+#+#+   +#+ */
// /*   Created: 2025/07/28 10:56:57 by fuulgen           #+#    #+# */
// /*   Updated: 2025/07/28 11:00:40 by fuulgen          ###   ########.fr */
// /* */
// /* **************************************************************************
// */
//
// #include "so_long.h"
//
// void init_game(t_game *game, char **map_data, t_vector map_size) {
//   game->mlx = mlx_init();
//   if (!game->mlx) {
//   }
//
//   game->win = mlx_new_window(game->mlx, map_size.x * TILE_SIZE,
//                              map_size.y * TILE_SIZE, "So Long");
//   if (!game->win) {
//   }
//
//   game->textures.wall = load_texture(game->mlx, "path_to_wall_texture.xpm");
//
//   locate_player(map_data, &game->player);
//   game->player.pixel = (t_vector){game->player.pos.x * TILE_SIZE,
//                                   game->player.pos.y * TILE_SIZE};
//
//   game->map = map_data;
//   game->map_size = map_size;
//
//   game->collectibles = calculate_collectibles(map_data);
//
//   game->collected = 0;
//   game->moves = 0;
//   game->game_won = 0;
// }
