#include "so_long.h"

static void *load_img(t_game *game, char *path)
{
    int   w;
    int   h;
    void *img;

    img = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
    if (!img)
        error_handler(MLX_FAIL);
    return (img);
}

void load_textures(t_game *game)
{
    game->textures.player = load_img(game, "assets/player.xpm");
    game->textures.wall = load_img(game, "assets/wall.xpm");
    game->textures.collectible = load_img(game, "assets/coin.xpm");
    game->textures.exit = load_img(game, "assets/door.xpm");
}

void draw_map(t_game *game)
{
    int y;
    int x;
    char tile;

    y = 0;
    while (y < game->map->size.y)
    {
        x = 0;
        while (x < game->map->size.x)
        {
            tile = game->map->grid[y][x];
            if (tile == '1')
                mlx_put_image_to_window(game->mlx, game->win,
                    game->textures.wall, x * TILE_SIZE, y * TILE_SIZE);
            else if (tile == 'P')
                mlx_put_image_to_window(game->mlx, game->win,
                    game->textures.player, x * TILE_SIZE, y * TILE_SIZE);
            else if (tile == 'C')
                mlx_put_image_to_window(game->mlx, game->win,
                    game->textures.collectible, x * TILE_SIZE, y * TILE_SIZE);
            else if (tile == 'E')
                mlx_put_image_to_window(game->mlx, game->win,
                    game->textures.exit, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}
