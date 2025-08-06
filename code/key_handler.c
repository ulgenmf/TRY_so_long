/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:55:05 by fuulgen           #+#    #+#             */
/*   Updated: 2025/08/05 20:09:54 by fuulgen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	shhitter(t_game *game, int nx, int ny)
{
	game->map->grid[game->map->player_loc.y][game->map->player_loc.x] = '0';
	game->map->player_loc.x = nx;
	game->map->player_loc.y = ny;
	game->map->grid[ny][nx] = 'P';
}

static void	try_move(t_game *game, int dx, int dy)
{
	int		nx;
	int		ny;
	char	dest;

	nx = game->map->player_loc.x + dx;
	ny = game->map->player_loc.y + dy;
	dest = game->map->grid[ny][nx];
	if (dest == '1')
		return ;
	if (dest == 'E' && game->collected != game->map->collectible_count)
	{
		ft_printf("\n get the flag first \n");
		return ;
	}
	if (dest == 'C')
		game->collected++;
	if (dest == 'E' && game->collected == game->map->collectible_count)
	{
		ft_printf("Moves: %d\n", ++game->moves);
		free_mlx_obj(&game);
		exit(EXIT_SUCCESS);
	}
	shhitter(game, nx, ny);
	ft_printf("Moves: %d\n", ++game->moves);
	draw_map(game);
}
// void logger(t_game *game, char dest) {
//   if (dest == '1')
//     return ;
//   if (dest == 'E' && game->collected != game->map->collectible_count)
//     ft_printf("You havent collected all the coins, --%d-- left",
//               game->map->collectible_count);
//   if (dest == 'C')
//     ft_printf("you got the big fat  C. \n");
//   game->collected++;
//   if (dest == 'E' && game->collected == game->map->collectible_count) {
//     ft_printf("Moves: %d\n", ++game->moves);
//     free_mlx_obj(&game);
//     exit(EXIT_SUCCESS);
//   }
// }
// static void try_move(t_game *game, int dx, int dy) {
//   int nx;
//   int ny;
//   char dest;
//
//   nx = game->map->player_loc.x + dx;
//   ny = game->map->player_loc.y + dy;
//   dest = game->map->grid[ny][nx];
//   logger(game, dest);
//   game->map->grid[game->map->player_loc.y][game->map->player_loc.x] = '0';
//   game->map->player_loc.x = nx;
//   game->map->player_loc.y = ny;
//   game->map->grid[ny][nx] = 'P';
//   ft_printf("Moves: %d\n", ++game->moves);
//   draw_map(game);
// }

int	key_hook(int keycode, t_game *mlx_obj)
{
	if (keycode == ESC_KEY)
	{
		free_mlx_obj(&mlx_obj);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 119 || keycode == 87)
		try_move(mlx_obj, 0, -1);
	else if (keycode == 97 || keycode == 65)
		try_move(mlx_obj, -1, 0);
	else if (keycode == 115 || keycode == 83)
		try_move(mlx_obj, 0, 1);
	else if (keycode == 100 || keycode == 68)
		try_move(mlx_obj, 1, 0);
	return (0);
}
