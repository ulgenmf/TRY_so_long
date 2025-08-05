#include "mlx/mlx.h"
#include "so_long.h"
#include <stdio.h>

void print_map_info(t_map *map) {
  int y;

  printf("Width: %d\n\n", map->size.x);
  printf("Height: %d\n\n", map->size.y);
  printf("Players: %d\n\n", map->player_count);
  printf("Player at: (%d, %d)\n\n", map->player_loc.x, map->player_loc.y);
  printf("Exits: %d\n\n", map->exit_count);
  printf("Exit at: (%d, %d)\n\n", map->exit_loc.x, map->exit_loc.y);
  printf("Collectibles: %d\n\n", map->collectible_count);
  printf("Collectible at: (%d, %d)\n\n", map->collectable_loc.x,
         map->collectable_loc.y);
  y = 0;
  printf("Grid:\n\n");
  while (map->grid && map->grid[y]) {
    printf("%s\n\n", map->grid[y]);
    y++;
  }
}

#include <stdio.h>

#include "mlx.h"

void show_all_images(void) {
  void *mlx;
  void *win;
  void *img_coin;
  void *img_door;
  void *img_player;
  void *img_wall;
  int w;
  int h;

  mlx = mlx_init();
  win = mlx_new_window(mlx, 1280, 1280, "Show Images");
  img_coin = mlx_xpm_file_to_image(mlx, "assets/coin.xpm", &w, &h);
  mlx_put_image_to_window(mlx, win, img_coin, 0, 0);
  img_door = mlx_xpm_file_to_image(mlx, "assets/door.xpm", &w, &h);
  mlx_put_image_to_window(mlx, win, img_door, 128, 0);
  img_player = mlx_xpm_file_to_image(mlx, "assets/player.xpm", &w, &h);
  mlx_put_image_to_window(mlx, win, img_player, 256, 0);
  img_wall = mlx_xpm_file_to_image(mlx, "assets/wall.xpm", &w, &h);
  mlx_put_image_to_window(mlx, win, img_wall, 384, 0);
  mlx_loop(mlx);
}

int main() { show_all_images(); }
// int main(void) {
//   t_map *map_obj;
//   t_game *mlx_obj;
//
//   run_that_shit("t.ber");
//   map_obj = create_obj("t.ber");
//   print_map_info(map_obj);
//   mlx_obj = mlx_init_(&map_obj);
//   mlx_key_hook(mlx_obj->win, key_hook, mlx_obj);
//   mlx_loop(mlx_obj->mlx);
//   free_mlx_obj(&mlx_obj);
//   //   free_map_object(map_obj);
//   return (0);
// }
