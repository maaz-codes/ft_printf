#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int ft_putnbr_hex_fd(unsigned long n, int fd, unsigned int cap)
{
    char num[10];
    const char *hex;
    int i;
    int count;

    count = 0;
    i = 0;
    if (cap == 1)
        hex = "0123456789ABCDEF";
    else
        hex = "0123456789abcdef";
    if (n == 0)
        count += ft_putchar_fd('0', fd);
    while (n != 0)
    {
        num[i++] = hex[n % 16];
        n = n / 16;
    }
    while (--i >= 0)
        count += ft_putchar_fd(num[i], fd);
    return count;
}