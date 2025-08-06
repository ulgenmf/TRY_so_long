/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:27:06 by fuulgen           #+#    #+#             */
/*   Updated: 2025/08/06 17:18:43 by fuulgen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_writer(char *str)
{
	int	i;

	write(2, "\033[31m", 5);
	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\033[0m", 4);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	check_file_name(char *file)
{
	char	*extension;
	size_t	len;
	size_t	ext_len;

	extension = ".ber";
	len = f_strlen(file);
	ext_len = f_strlen(extension);
	if (len < ext_len || ft_strcmp(file + len - ext_len, extension) != 0)
	{
		extension = file;
		writer(extension);
		error_writer("invalid file name  \n");
		exit(EXIT_FAILURE);
	}
	ft_printf("\033[33mPassed: File name is correct { %s } \033[0m\n", file);
}
