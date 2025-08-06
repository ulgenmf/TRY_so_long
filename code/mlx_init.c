/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:14:52 by fuulgen           #+#    #+#             */
/*   Updated: 2025/08/06 17:11:30 by fuulgen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// typedef struct s_game {
//   void *mlx;
//   void *win;
//   t_map map;
//   int moves;
//   int collected;
// } t_game;

void	shitter(t_game *obj)
{
	obj->textures.player = NULL;
	obj->textures.wall = NULL;
	obj->textures.floor = NULL;
	obj->textures.exit = NULL;
	obj->textures.collectible = NULL;
}

void	check_map_size(t_game *obj)
{
	if (obj->map->size.x > 15 || obj->map->size.y > 15)
	{
		free_mlx_obj(&obj);
		ft_printf("ajkhjhksajkdsajkasdkjsadjksas");
		error_handler(MLX_FAIL);
	}
}

t_game	*mlx_init_(t_map **map_obj)
{
	t_game	*obj;
	void	*mlx;
	void	*window;

	mlx = mlx_init();
	window = mlx_new_window(mlx, TILE_SIZE * (*map_obj)->size.x, TILE_SIZE
			* (*map_obj)->size.y, "shit");
	obj = malloc(sizeof(t_game));
	if (!obj)
	{
		if (window)
			mlx_destroy_window(mlx, window);
		if (mlx)
			mlx_destroy_display(mlx);
		free(mlx);
		error_handler(MLX_FAIL);
	}
	obj->mlx = mlx;
	obj->win = window;
	obj->map = *map_obj;
	shitter(obj);
	obj->moves = 0;
	obj->collected = 0;
	return (obj);
}

void	free_mlx_obj(t_game **obj)
{
	if (!obj || !*obj)
		return ;
	if ((*obj)->textures.player)
		mlx_destroy_image((*obj)->mlx, (*obj)->textures.player);
	if ((*obj)->textures.wall)
		mlx_destroy_image((*obj)->mlx, (*obj)->textures.wall);
	if ((*obj)->textures.exit)
		mlx_destroy_image((*obj)->mlx, (*obj)->textures.exit);
	if ((*obj)->textures.collectible)
		mlx_destroy_image((*obj)->mlx, (*obj)->textures.collectible);
	if ((*obj)->textures.floor)
		mlx_destroy_image((*obj)->mlx, (*obj)->textures.floor);
	free_map_object((*obj)->map);
	mlx_destroy_window((*obj)->mlx, (*obj)->win);
	mlx_destroy_display((*obj)->mlx);
	free((*obj)->mlx);
	free(*obj);
}
