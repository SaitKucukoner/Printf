#include "ft_printf.h"

void ft_putchar(char c, int *counter)
{
    write(1, &c, 1);
    *counter += 1;
}

void ft_putstr(char *str, int *counter)
{
    int i;

    i = 0;
    if (!str)
    {
        *counter += write(1, "(null)", 6);
        return;
    }
    while (str[i])
    {
        *counter += write(1, &str[i], 1);
        i++;
    }
}
void ft_putnbr(int number, int *counter)
{
    char result;

    if (number == -2147483648)
    {
        write(1, "-2147483648", 11);
        *counter += 11;
    }
    else if (number < 0)
    {
        write(1, "-", 1);
        *counter += 1;
        ft_putnbr(-number, counter);
    }
    else
    {
        if (number > 9)
            ft_putnbr((number / 10), counter);
        result = (number % 10) + '0';
        *counter += write(1, &result, 1);
    }
}
void ft_putunbr(unsigned int number, int *counter)
{
    char result;

    if (number > 9)
        ft_putunbr((number / 10), counter);
    result = (number % 10) + '0';
    *counter += write(1, &result, 1);
}

void ft_puthex_p(unsigned long number, int *counter)
{
    char result;
    char *hexbase;

    hexbase = "0123456789abcdef";
    if (number >= 16)
        ft_puthex_p((number / 16), counter);
    result = hexbase[number % 16];
    *counter += write(1, &result, 1);
}

void ft_puthex(char format, unsigned int number, int *counter)
{
    char result;
    char *hexbase;

    if (format == 'X')
        hexbase = "0123456789ABCDEF";
    else
        hexbase = "0123456789abcdef";
    if (number >= 16)
        ft_puthex(format, (number / 16), counter);
    result = hexbase[number % 16];
    *counter += write(1, &result, 1);
}