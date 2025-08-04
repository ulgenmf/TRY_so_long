#include "mlx/mlx.h"
#include "so_long.h"
#include <stdio.h>

void	print_map_info(t_map *map)
{
	int	y;

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
	while (map->grid && map->grid[y])
	{
		printf("%s\n\n", map->grid[y]);
		y++;
	}
}

int	main(void)
{
	t_map	*map_obj;
	t_game	*mlx_obj;

	run_that_shit("t.ber");
	map_obj = create_obj("t.ber");
	print_map_info(map_obj);
	mlx_obj = mlx_init_(map_obj);
	// mlx_loop(mlx_obj->mlx);
	free_map_object(map_obj);
	free_mlx_obj(mlx_obj);
	return (0);
}
