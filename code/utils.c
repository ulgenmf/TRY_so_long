/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:57:01 by fuulgen           #+#    #+#             */
/*   Updated: 2025/08/03 17:16:05 by fuulgen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

size_t	f_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	writer(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	new_line_calc(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			j++;
		i++;
	}
	return (j + 1);
}

char	*my_strcpy(char *dest, const char *src)
{
	char	*original_dest;

	original_dest = dest;
	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (original_dest);
}
// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	unsigned int	i;
// 	const char		*buffer1;
// 	char			*buffer2;

// 	i = 0;
// 	buffer1 = (char *)src;
// 	buffer2 = dst;
// 	while (i < n && (src || dst))
// 	{
// 		buffer2[i] = buffer1[i];
// 		i++;
// 	}
// 	return (dst);
// }

// char	*ft_strdup(char *src)
// {
// 	size_t	size;
// 	char	*dest;

// 	size = f_strlen(src);
// 	dest = (char *)malloc(size * sizeof(char) + 1);
// 	if (dest == NULL)
// 		return (0);
// 	ft_memcpy(dest, src, size);
// 	dest[size] = '\0';
// 	return (dest);
// }
