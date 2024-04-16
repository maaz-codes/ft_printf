#include <unistd.h>
#include "ft_printf.h"

int ft_putnbr_pos_fd(unsigned int n, int fd)
{
    unsigned long temp;
    char num[10];
    int i;
    int count;

    temp = n;
    count = 0;
    if (temp < 0)
		return (-1);
    if (temp == 0)
        count += ft_putchar_fd('0', fd);
    i = 0;
    while (temp != 0)
    {
        num[i] = (temp % 10) + '0';
        temp = temp / 10;
        i++;
    }
    while (--i >= 0)
        count += ft_putchar_fd(num[i], fd);
    return (count);
}