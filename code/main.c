/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:10:27 by fuulgen           #+#    #+#             */
/*   Updated: 2025/08/06 17:21:12 by fuulgen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*shitter(int shit, char **shits)
{
	char	*file_n;

	if (shit != 2)
	{
		ft_printf("\n Map name is not passed, bye \n");
		exit(EXIT_FAILURE);
	}
	else
	{
		file_n = shits[1];
	}
	return (file_n);
}

int	main(int shit, char **shits)
{
	char	*file_n;
	t_map	*map_obj;
	t_game	*game;

	file_n = shitter(shit, shits);
	map_obj = create_obj(file_n);
	if (!map_obj)
		return (1);
	run_that_shit(file_n);
	game = mlx_init_(&map_obj);
	if (!game)
		return (1);
	check_map_size(game);
	load_textures(game);
	draw_map(game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_loop(game->mlx);
	free_mlx_obj(&game);
	return (0);
}
