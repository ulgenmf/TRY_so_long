/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 23:19:26 by fuulgen           #+#    #+#             */
/*   Updated: 2025/08/03 18:17:09 by fuulgen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**duplicate_map(char **map)
{
	int		len;
	int		i;
	char	**dup;

	i = 0;
	len = 0;
	while (map[len])
		len++;
	dup = (char **)malloc((len + 1) * sizeof(char *));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = ft_strdup(map[i]);
		if (!dup[i])
		{
			while (i-- > 0)
				free(dup[i]);
			free(dup);
			return (NULL);
		}
		i++;
	}
	dup[len] = NULL;
	return (dup);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	find_player(char **map, int *px, int *py)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				*px = x;
				*py = y;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (-1);
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == '0' || map[y][x] == 'C' || map[y][x] == 'P' ||
		map[y][x] == 'E')
		map[y][x] = 'V';
	if (y > 0)
		flood_fill(map, x, y - 1);
	if (map[y + 1])
		flood_fill(map, x, y + 1);
	if (x > 0)
		flood_fill(map, x - 1, y);
	if (map[y][x + 1])
		flood_fill(map, x + 1, y);
}

int	path_valid(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}
