/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:53:58 by bkaztaou          #+#    #+#             */
/*   Updated: 2025/09/28 10:00:00 by fuulgen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    *newline_exist(char *str)
{
        int     i;

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

/*
** Join two strings and free the originals.
**
** `leftover` may be NULL on the first call. In that case an empty
** string is allocated so that the concatenation behaves as expected.
** `buff` must be a valid allocated string. The returned string is a
** newly allocated buffer containing the concatenation of both inputs.
*/
char    *ft_strjoin_gnl(char *leftover, char *buff)
{
        char    *temp;
        size_t  i;
        size_t  j;

        if (!leftover && !buff)
                return (NULL);
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

