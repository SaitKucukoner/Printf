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
    while (str[i])
    {
        write(1, &str[i], 1);
        *counter += 1;
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