/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fuulgen <fuulgen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:17:52 by fuulgen           #+#    #+#             */
/*   Updated: 2025/06/26 18:27:32 by fuulgen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int hex, char c, unsigned int *counter)
{
	char	*digits;

	if (c == 'X')
		digits = "0123456789ABCDEF";
	else
		digits = "0123456789abcdef";
	if (hex >= 16)
		ft_puthex(hex / 16, c, counter);
	*counter += write(1, &digits[hex % 16], 1);
}

void	ft_puthexp(unsigned long hex, unsigned int *counter)
{
	char	*digits;

	digits = "0123456789abcdef";
	if (hex >= 16)
		ft_puthexp(hex / 16, counter);
	*counter += write(1, &digits[hex % 16], 1);
}

void	ft_putptr(void *ptr, unsigned int *counter)
{
	if (ptr == NULL)
	{
		*counter += write(1, "(nil)", 5);
		return ;
	}
	*counter += write(1, "0x", 2);
	ft_puthexp((unsigned long)ptr, counter);
}
