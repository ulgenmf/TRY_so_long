#include "so_long.h"

int main(void)
{
    t_map  *map_obj;
    t_game *game;

    map_obj = create_obj(DEFAULT_MAP);
    if (!map_obj)
        return (1);
    game = mlx_init_(&map_obj);
    if (!game)
        return (1);
    load_textures(game);
    draw_map(game);
    mlx_key_hook(game->win, key_hook, game);
    mlx_loop(game->mlx);
    free_mlx_obj(&game);
    return (0);
}
