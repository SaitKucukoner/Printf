#include "ft_printf.h"

static void ft_format_conversion(const char *format, int *counter, va_list args)
{
    if (*format == 'c')
        ft_putchar(va_arg(args, int), counter); // %c Prints a single character.
    else if (*format == 's')
        ft_putstr(va_arg(args, char *), counter); // %s Prints a string (as defined by the common C convention).
    else if (*format == 'p')
    {
        /* %p The void * pointer argument has to be printed in hexadecimal format. */
    }
    else if (*format == 'd')
    {
        /* %d Prints a decimal (base 10) number. */
    }
    else if (*format == 'i')
    {
        /* %i Prints an integer in base 10. */
    }
    else if (*format == 'u')
    {
        /* %u Prints an unsigned decimal (base 10) number. */
    }
    else if (*format == 'x')
    {
        /* %x Prints a number in hexadecimal (base 16) lowercase format. */
    }
    else if (*format == 'X')
    {
        /* %X Prints a number in hexadecimal (base 16) uppercase format. */
    }
    else if (*format == '%')
    {
        /* %% Prints a percent sign */
    }
}
#include <stdio.h>

int ft_printf(const char *format, ...)
{
    int counter;
    int i;
    va_list args;

    counter = 0;
    i = 0;
    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            ft_format_conversion(&format[i + 1], &counter, args);
        }
        i++;
    }
    printf("\n%d\n", counter);
}
