/* **************************************************************************
 */
/* */
/*                                                        :::      ::::::::
 */
/*   mlx_init.c                                         :+:      :+:    :+:
 */
/*                                                    +:+ +:+         +:+ */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+ */
/*                                                +#+#+#+#+#+   +#+ */
/*   Created: 2025/07/28 10:56:57 by fuulgen           #+#    #+# */
/*   Updated: 2025/07/28 11:00:40 by fuulgen          ###   ########.fr */
/* */
/* **************************************************************************
 */
//
#include "mlx/mlx.h"
#include "so_long.h"

// typedef struct s_game {
//   void *mlx;
//   void *win;
//   t_map map;
//   int moves;
//   int collected;
// } t_game;

t_game	*mlx_init_(t_map *map_obj)
{
	t_game	*obj;
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1280, 1280, "shit");
	obj = malloc(sizeof(t_game));
	if (!obj)
	{
		free(obj);
		error_handler(MLX_FAIL);
	}
	obj->mlx = mlx;
	obj->win = window;
	obj->map = *map_obj;
	obj->moves = 0;
	obj->collected = 0;
	return (obj);
}

void	free_mlx_obj(t_game *obj)
{
	// t_map map;
	// map = obj->map;
	// free_map_object(&map);
	// free_map_object(&obj->map);
	mlx_destroy_window(obj->mlx, obj->win);
	mlx_destroy_display(obj->mlx);
	free(obj->mlx);

  free(obj);
}
