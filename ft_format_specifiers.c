#include <unistd.h>
#include <stdarg.h>
#include "libftprintf.h"

int ft_format_specifiers(char fs, va_list args)
{
    int count;

    if (fs == 'c')
        count = ft_putchar_fd((char)va_arg(args, int), 1);
    else if (fs == 's')
		count = ft_putstr_fd(va_arg(args, char *), 1);
    else if (fs == 'd' || fs == 'i')
		count = ft_putnbr_fd(va_arg(args, int), 1);
    else if (fs == 'u')
		count = ft_putnbr_pos_fd(va_arg(args, unsigned int), 1);
    else if (fs == 'x')
		count = ft_putnbr_hex_fd(va_arg(args, int), 1, 0); 
    else if (fs == 'X')
		count = ft_putnbr_hex_fd(va_arg(args, int), 1, 1); 
    else if (fs == '%')
		count = ft_putchar_fd('%', 1);
    else if (fs == 'p')
		count = ft_putadd_fd(va_arg(args, int), 1);
    else
		count = -1;
    return (count);
}