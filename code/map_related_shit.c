/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_related_shit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 07:51:47 by fuulgen           #+#    #+#             */
/*   Updated: 2025/08/06 17:18:20 by fuulgen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	wait_(int n)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 200000000 * n;
// 	while (i < count)
// 		i++;
// }
void	parse_map(char **map, char *file_name)
{
	char	**map_cpy;

	map_cpy = map;
	ft_printf("Checking the map \n\n");
	while (*map)
	{
		ft_printf("%s\n", *map++);
	}
	ft_printf("\n**********\n");
	big_fat_error_handler(map_cpy, file_name);
	write(1, "\033[32mSuccess!\033[0m\n", 18);
}

int	is_map_solvable(char **src_map)
{
	char	**map;
	int		px;
	int		py;
	int		result;

	map = duplicate_map(src_map);
	if (!map)
		return (-1);
	if (find_player(map, &px, &py) == -1)
	{
		free_map(map);
		return (-1);
	}
	flood_fill(map, px, py);
	result = path_valid(map);
	free_map(map);
	return (result);
}

void	big_fat_error_handler(char **map, char *file_name)
{
	if (!map)
	{
		error_writer("problem with map check main.c:2");
		exit(EXIT_FAILURE);
	}
	if (is_surrounded_by_walls(map))
	{
		ft_printf("\033[33mPassed: Map is surrounded by walls.\033[0m\n");
	}
	else
	{
		error_handler(UNCLOSED_MAP);
	}
	if (is_rectangular(map))
	{
		ft_printf("\033[33mPassed: Map is rectangular.\033[0m\n");
	}
	else
	{
		error_handler(NOT_RECTANGULAR);
	}
	check_file_name(file_name);
	check_elements(map);
}

void	run_that_shit(char *argv_file_name)
{
	char	**map;
	int		flood_result;
	int		i;

	i = 0;
	map = get_map(argv_file_name);
	parse_map(map, argv_file_name);
	flood_result = is_map_solvable(map);
	if (flood_result == 0)
		writer("\n\n\033[32mMAP IS LEGIT !\033[0m\n");
	else
	{
		error_writer("\nMap is not solvable `flood fill err`\n");
		exit(EXIT_FAILURE);
	}
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
