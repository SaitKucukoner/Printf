/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skucukon <skucukon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:55:55 by skucukon          #+#    #+#             */
/*   Updated: 2025/08/01 18:13:21 by skucukon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *counter)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		*counter += 6;
		return ;
	}
	while (str[i])
	{
		*counter += write(1, &str[i], 1);
		i++;
	}
}

void	ft_puthex_p(unsigned long number, int *counter)
{
	if (number == 0)
	{
		ft_putstr("(nil)", counter);
		return ;
	}
	else
	{
		ft_putstr("0x", counter);
		ft_puthex("x", number, counter);
	}
}

void	ft_putnbr(int number, int *counter)
{
	char	c;

	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		*counter += 11;
	}
	else if (number < 0)
	{
		*counter += write(1, "-", 1);
		ft_putnbr(-number, counter);
	}
	else
	{
		if (number > 9)
			ft_putnbr((number / 10), counter);
		c = (number % 10) + '0';
		*counter += write(1, &c, 1);
	}
}

void	ft_putnbr_u(unsigned int number, int *counter)
{
	char	c;

	if (number > 9)
		ft_putnbr_u((number / 10), counter);
	c = number % 10 + '0';
	*counter += write(1, &c, 1);
}

void	ft_puthex(const char *format, unsigned long number, int *counter)
{
	char	*hexbase;

	if (*format == 'x')
		hexbase = "0123456789abcdef";
	else
		hexbase = "0123456789ABCDEF";
	if (number >= 16)
		ft_puthex(format, (number / 16), counter);
	*counter += write(1, &hexbase[number % 16], 1);
}
