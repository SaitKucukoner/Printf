/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skucukon <skucukon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:57:20 by skucukon          #+#    #+#             */
/*   Updated: 2025/07/30 20:04:19 by skucukon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putchar(char c, int *counter);
void	ft_format_converter(const char *format, va_list args, int *counter);
int		ft_printf(const char *format, ...);
void	ft_putstr(char *str, int *counter);
void	ft_puthex_p(unsigned long number, int *counter);
void	ft_putnbr(int number, int *counter);
void	ft_putnbr_u(unsigned int number, int *counter);
void	ft_puthex(const char *format, unsigned long number, int *counter);

#endif