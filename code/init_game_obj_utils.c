/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_obj_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:36:20 by fuulgen           #+#    #+#             */
/*   Updated: 2025/08/05 18:44:42 by fuulgen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player2(t_map *object)
{
	int		y;
	int		x;
	char	**map;

	y = 0;
	map = object->grid;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				object->player_loc.x = x;
				object->player_loc.y = y;
			}
			x++;
		}
		y++;
	}
	object->size.x = x;
	object->size.y = y;
}

void	find_collectable(t_map *object)
{
	int		y;
	int		x;
	char	**map;

	y = 0;
	map = object->grid;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
			{
				object->collectable_loc.x = x;
				object->collectable_loc.y = y;
				object->collectible_count++;
			}
			x++;
		}
		y++;
	}
}

void	find_exit(t_map *object)
{
	int		y;
	int		x;
	char	**map;

	y = 0;
	map = object->grid;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				object->exit_loc.x = x;
				object->exit_loc.y = y;
			}
			x++;
		}
		y++;
	}
}

void	get_locations(t_map *object)
{
	find_player2(object);
	find_collectable(object);
	find_exit(object);
}
