#include <unistd.h>
#include "ft_printf.h"

int ft_putnbr_pos_fd(unsigned long n, int fd)
{
    char num[10];
    int i;
    int count;

    count = 0;
    if (n < 0)
		return (-1);
    if (n == 0)
        count += ft_putchar_fd('0', fd);
    i = 0;
    while (n != 0)
    {
        num[i] = (n % 10) + '0';
        n = n / 10;
        i++;
    }
    while (--i >= 0)
        count += ft_putchar_fd(num[i], fd);
    return (count);
}