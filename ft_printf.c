#include "ft_printf.h"

static void ft_format_conversion(const char *format, int *counter, va_list args)
{
    if (*format == 'c')
        ft_putchar(va_arg(args, int), counter); // %c Prints a single character.
    else if (*format == 's')
        ft_putstr(va_arg(args, char *), counter); // %s Prints a string (as defined by the common C convention).
    else if (*format == 'd' || *format == 'i')
        ft_putnbr(va_arg(args, int), counter); /* %d Prints a decimal (base 10) number. */ /// /* %i Prints an integer in base 10. */
    else if (*format == 'u')
        ft_putunbr(va_arg(args, int), counter); /* %u Prints an unsigned decimal (base 10) number. */
    else if (*format == 'p')
    {
        /* %p The void * pointer argument has to be printed in hexadecimal format. */
    }
    else if (*format == 'x' || *format == "X")
    {
        /* %x Prints a number in hexadecimal (base 16) lowercase || uppercase format . */
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
            if (format[i + 1] == '%')
                counter += write(1, "%", 1);
            else
                ft_format_conversion(&format[i + 1], &counter, args);
            i++;
        }
        else
            counter += write(1, &format[i], 1);
        i++;
    }
    va_end(args);
    printf("\n%d\n", counter);
}
