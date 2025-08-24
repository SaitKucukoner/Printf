# ft_printf

This project is a recreation of the standard C library function `printf()`.  
The goal is to implement a simplified version of `printf` that handles a limited set of format specifiers.  
This exercise is crucial for understanding how variadic functions work in C (functions that accept a variable number of arguments).

---

## Features

The `ft_printf` function handles the following standard format conversions:

| Conversion | Description                               | Example                        |
|------------|-------------------------------------------|--------------------------------|
| `%c`       | Prints a single character                 | `ft_printf("%c", 'A')`         |
| `%s`       | Prints a string of characters             | `ft_printf("%s", "Hello")`     |
| `%p`       | Prints the pointer address (in hexadecimal) | `ft_printf("%p", &var)`        |
| `%d`       | Prints a signed decimal integer           | `ft_printf("%d", 42)`          |
| `%i`       | Prints a signed integer (same as `%d`)    | `ft_printf("%i", -10)`         |
| `%u`       | Prints an unsigned decimal integer
