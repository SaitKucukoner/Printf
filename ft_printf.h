#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

void ft_putchar(char c , int *counter);
void ft_putstr(char *str, int *counter);
void ft_putnbr(int number, int *counter);
void ft_putunbr(unsigned int number, int *counter);
void ft_puthex_p(unsigned long number, int *counter);
void ft_puthex(char format, unsigned int number, int *counter);
int ft_printf(const char *format, ...);

#endif