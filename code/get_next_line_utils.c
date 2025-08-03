/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:53:58 by bkaztaou          #+#    #+#             */
/*   Updated: 2025/07/28 10:36:08 by fuulgen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*newline_exist(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

// size_t	ft_strlen(char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strjoin(char *leftover, char *buff)
// {
// 	int		i;
// 	int		j;
// 	char	*temp;

// 	if (!leftover && !buff)
// 		return (NULL);
// 	if (!leftover)
// 		leftover = ft_calloc(1, sizeof(char));
// 	temp = malloc(sizeof(char) * (ft_strlen(leftover) + ft_strlen(buff) + 1));
// 	if (!temp)
// 		return (NULL);
// 	i = -1;
// 	while (leftover[++i])
// 		temp[i] = leftover[i];
// 	j = -1;
// 	while (buff[++j])
// 		temp[i++] = buff[j];
// 	temp[i] = '\0';
// 	return (free(leftover), free(buff), temp);
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	size_t	i;
// 	char	*ptr;

// 	i = 0;
// 	if (count && size > SIZE_MAX / count)
// 		return (NULL);
// 	ptr = malloc(count * size);
// 	if (!ptr)
// 		return (NULL);
// 	while (i < count)
// 	{
// 		ptr[i] = '\0';
// 		i++;
// 	}
// 	return (ptr);
// }
