/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 17:17:16 by fuulgen           #+#    #+#             */
/*   Updated: 2025/08/03 17:17:17 by fuulgen          ###   ########.fr       */
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

char	*ft_strjoin_gnl(char *leftover, char *buff)
{
	char	*temp;
	size_t	i;
	size_t	j;

	if (!leftover)
	{
		leftover = ft_calloc(1, sizeof(char));
		if (!leftover)
			return (free(buff), NULL);
	}
	temp = malloc(ft_strlen(leftover) + ft_strlen(buff) + 1);
	if (!temp)
		return (free(leftover), free(buff), NULL);
	i = 0;
	while (leftover[i])
	{
		temp[i] = leftover[i];
		i++;
	}
	j = 0;
	while (buff[j])
		temp[i++] = buff[j++];
	temp[i] = '\0';
	free(leftover);
	free(buff);
	return (temp);
}
