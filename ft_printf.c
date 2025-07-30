/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skucukon <skucukon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:37:57 by skucukon          #+#    #+#             */
/*   Updated: 2025/07/30 19:55:47 by skucukon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *counter)
{
	*counter += write(1, &c, 1);
}

void	ft_format_converter(const char *format, va_list args, int *counter)
{
	if (*format == 'c')
		ft_putchar(va_arg(args, int), counter);
	else if (*format == 's')
		ft_putstr(va_arg(args, char *), counter);
	else if (*format == 'p')
		ft_puthex_p(va_arg(args, unsigned long), counter);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(args, int), counter);
	else if (*format == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), counter);
	else if (*format == 'x' || *format == 'X')
		ft_puthex(format, va_arg(args, unsigned int), counter);
}

int	ft_printf(const char *format, ...)
{
	int		counter;
	int		i;
	va_list	args;

	counter = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
				counter += write(1, "%", 1);
			else
				ft_format_converter(&format[i + 1], args, &counter);
			i += 2;
		}
		else
		{
			counter += write(1, &format[i], 1);
			i++;
		}
	}
	va_end(args);
	return (counter);
}
