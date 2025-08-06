/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 21:30:58 by fuulgen           #+#    #+#             */
/*   Updated: 2025/08/05 20:14:27 by fuulgen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_line_counter(const char *map_path)
{
	int		fd;
	int		line_n;
	char	*temp;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		error_handler(UNKNOWN_ERROR);
	}
	line_n = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		line_n++;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	return (line_n);
}

char	*get_map_line(int fd)
{
	char	*temp;

	temp = get_next_line(fd);
	if (!temp)
	{
		return (NULL);
	}
	return (temp);
}

char	*process_line(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
	{
		line[len - 1] = '\0';
	}
	return (line);
}

static void	fill_map_data(int fd, char **map)
{
	int		index;
	char	*line;

	index = 0;
	line = get_map_line(fd);
	while (line)
	{
		line = process_line(line);
		map[index] = ft_strdup(line);
		if (!map[index])
		{
			while (index > 0)
			{
				index--;
				free(map[index]);
			}
			free(map);
			close(fd);
			error_handler(MLX_FAIL);
		}
		index++;
		free(line);
		line = get_map_line(fd);
	}
	map[index] = NULL;
}

char	**get_map(char *m)
{
	int		line_n;
	int		fd;
	char	**map;

	line_n = map_line_counter(m);
	fd = open(m, O_RDONLY);
	if (fd < 0)
	{
		error_handler(UNKNOWN_ERROR);
	}
	map = malloc(sizeof(char *) * (line_n + 1));
	if (!map)
	{
		close(fd);
		error_handler(MLX_FAIL);
	}
	fill_map_data(fd, map);
	close(fd);
	return (map);
}
