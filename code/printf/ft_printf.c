/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:17:48 by fuulgen           #+#    #+#             */
/*   Updated: 2025/06/26 18:21:38 by fuulgen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flagger(const char *s, va_list args, unsigned int *counter)
{
	char	c;

	if (*s == 'c')
	{
		c = (char)va_arg(args, int);
		*counter += write(1, &c, 1);
	}
	else if (*s == 's')
		ft_putstr(va_arg(args, char *), counter);
	else if (*s == 'd' || *s == 'i')
		ft_putnbr(va_arg(args, int), counter);
	else if (*s == 'u')
		ft_putunbr(va_arg(args, unsigned int), counter);
	else if (*s == 'x' || *s == 'X')
		ft_puthex(va_arg(args, unsigned int), *s, counter);
	else if (*s == '%')
		*counter += write(1, "%", 1);
	else if (*s == 'p')
		ft_putptr(va_arg(args, void *), counter);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	counter;

	counter = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			flagger(format, args, &counter);
		}
		else
			counter += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (counter);
}
