#include <unistd.h>
#include "ft_printf.h"

int ft_putadd_fd(unsigned long n, int fd)
{
    char num[10];
    const char *hex;
    int i;
    int count;

    count = 0;
    i = 0;
    hex = "0123456789ABCDEF";
    if (n == 0)
        count += ft_putchar_fd('0', fd);
    while (n != 0)
    {
        num[i++] = hex[n % 16];
        n = n / 16;
    }
    num[i] = 'x';
    num [++i] = '0';
    while (i >= 0)
        count += ft_putchar_fd(num[i--], fd);
    return (count + 2);
}