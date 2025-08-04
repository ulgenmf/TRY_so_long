/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 17:25:29 by fuulgen           #+#    #+#             */
/*   Updated: 2025/08/04 11:40:56 by fuulgen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*create_obj(char *file_name)
{
	t_map	*obj;
	char	**map;

	map = get_map(file_name);
	if (!map)
		return (NULL);
	obj = (t_map *)malloc(sizeof(t_map));
	if (!obj)
	{
		free_map_object(obj);
		error_handler(MLX_FAIL);
	}
	obj->grid = duplicate_map(map);
	obj->player_count = 0;
	obj->exit_count = 0;
	obj->collectible_count = 0;
	get_locations(obj);
	free_map(map);
	return (obj);
}

void	free_map_object(t_map *object)
{
	char	**map;

	map = object->grid;
	if (!object)
		return ;
	free_map(map);
	free(object);
}
