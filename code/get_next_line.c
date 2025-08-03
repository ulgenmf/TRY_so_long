/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:54:06 by bkaztaou          #+#    #+#             */
/*   Updated: 2025/07/19 13:36:24 by fuulgen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_file(int fd, char *leftover)
{
	char	*buff;
	int		readed;

	readed = 1;
	while (!newline_exist(leftover) && readed != 0)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buff)
			return (NULL);
		readed = (int)read(fd, buff, BUFFER_SIZE);
		if ((!leftover && readed == 0) || readed == -1)
			return (free(buff), NULL);
		buff[readed] = '\0';
                leftover = ft_strjoin_gnl(leftover, buff);
	}
	return (leftover);
}

char	*ft_get_line(char *leftover)
{
	char	*line;
	int		i;

	if (!leftover)
		return (NULL);
	i = 0;
	while (leftover[i] && leftover[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = -1;
	while (leftover[++i] && leftover[i] != '\n')
		line[i] = leftover[i];
	if (leftover[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_get_rest(char *leftover, char *line)
{
	char	*rest;
	int		i;
	int		j;

	i = ft_strlen(line);
	if (!leftover[i])
		return (free(leftover), NULL);
	j = 0;
	while (leftover[i++])
		j++;
	rest = malloc(sizeof(char) * (j + 1));
	if (!rest)
		return (NULL);
	i = ft_strlen(line);
	j = 0;
	while (leftover[i])
		rest[j++] = leftover[i++];
	rest[j] = '\0';
	return (free(leftover), rest);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = read_file(fd, leftover);
	if (!temp)
	{
		if (leftover)
			free(leftover);
		leftover = NULL;
		return (NULL);
	}
	leftover = temp;
	line = ft_get_line(leftover);
	leftover = ft_get_rest(leftover, line);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(int argc, char *argv[])
// {
// 	int fd;
// 	char *line;

// 	if (argc != 2)
// 	{
// 		printf("Usage: %s filename\n", argv[0]);
// 		return (1);
// 	}

// 	fd = open(argv[1], O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}

// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}

// 	close(fd);
// 	return (0);
// }