/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:05:15 by fuulgen           #+#    #+#             */
/*   Updated: 2025/08/03 17:31:31 by fuulgen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_handler(t_errors error)
{
	if (error == MAP_FILE_TOO_BIG)
		error_writer("Error\nMap file too big\n");
	else if (error == INVALID_CHAR)
		error_writer("Error\nInvalid character in map\n");
	else if (error == NOT_RECTANGULAR)
		error_writer("Error\nMap is not rectangular\n");
	else if (error == UNCLOSED_MAP)
		error_writer("Error\nMap is not surrounded by walls\n");
	else if (error == WRONG_ELEMENT_COUNT)
		error_writer(
			"Error\nWrong number of start, exit,  collectibles or map name \n");
	else if (error == NO_PATH)
		error_writer("Error\nNo valid path to exit and collectibles\n");
	else if (error == MLX_FAIL)
		error_writer("Error\nGraphics initialization failed\n");
	else
		error_writer("Error\nUnknown error\n");
	write(2,
			"\033[31m\n ***Errors are propably broken"
			" ignore the explanation of the "
			"error*** \n\033[0m",
			77);
	//    exit(EXIT_FAILURE);`
}

void	element_count(int *p_count, int *e_count, int *c_count, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				(*p_count)++;
			else if (map[i][j] == 'E')
				(*e_count)++;
			else if (map[i][j] == 'C')
				(*c_count)++;
			else if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '\n')
				error_handler(INVALID_CHAR);
			j++;
		}
		i++;
	}
}

int	check_elements(char **map)
{
	int	p_count;
	int	e_count;
	int	c_count;

	p_count = 0;
	e_count = 0;
	c_count = 0;
	element_count(&p_count, &e_count, &c_count, map);
	if (p_count != 1 || e_count != 1 || c_count < 1)
		error_handler(WRONG_ELEMENT_COUNT);
	ft_printf("\033[33mPassed: Correct amount"
				"of element counts { P = %d E = %d "
				"C = %d }\033[0m\n",
				p_count,
				e_count,
				c_count);
	return (c_count);
}

int	is_rectangular(char **map)
{
	int	width;
	int	row;
	int	col;

	if (!map || !map[0])
		return (0);
	width = 0;
	while (map[0][width] && map[0][width] != '\0')
		width++;
	row = 1;
	while (map[row])
	{
		col = 0;
		while (map[row][col] && map[row][col] != '\0')
			col++;
		if (col != width)
			return (0);
		row++;
	}
	return (1);
}

int	is_surrounded_by_walls(char **map)
{
	int	i;
	int	w;
	int	h;

	h = 0;
	while (map[h])
		h++;
	w = 0;
	while (map[0][w])
		w++;
	i = 0;
	while (i < w)
	{
		if (map[0][i] != '1' || map[h - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < h)
	{
		if (map[i][0] != '1' || map[i][w - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
