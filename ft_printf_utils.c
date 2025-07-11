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