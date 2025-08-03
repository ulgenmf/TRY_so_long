/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:17:52 by fuulgen           #+#    #+#             */
/*   Updated: 2025/06/26 18:29:03 by fuulgen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(const char *s, unsigned int *counter)
{
	int	i;

	i = 0;
	if (!s)
	{
		*counter += write(1, "(null)", 6);
		return ;
	}
	while (s[i] != '\0')
	{
		*counter += write(1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr(int n, unsigned int *counter)
{
	char	res;

	if (n == -2147483648)
	{
		ft_putnbr(n / 10, counter);
		*counter += write(1, "8", 1);
	}
	else if (n < 0)
	{
		*counter += write(1, "-", 1);
		ft_putnbr(-n, counter);
	}
	else
	{
		if (n > 9)
			ft_putnbr(n / 10, counter);
		res = (n % 10) + '0';
		*counter += write(1, &res, 1);
	}
}

void	ft_putunbr(unsigned int n, unsigned int *counter)
{
	char	res;

	if (n > 9)
		ft_putunbr(n / 10, counter);
	res = (n % 10) + '0';
	*counter += write(1, &res, 1);
}
