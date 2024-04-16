#include <unistd.h>
#include "libftprintf.h"

int ft_putadd_fd(int n, int fd)
{
    long temp;
    char num[20];
    char hex[17] = "0123456789ABCDEF";
    int i;
    int count;

    temp = n;
    count = 0;
    if (temp < 0)
        temp = temp * -1;
    if (temp == 0)
        count += ft_putchar_fd('0', fd);
    i = 0;
    while (temp != 0)
    {
        num[i] = hex[temp % 16];
        temp = temp / 16;
        i++;
    }
    num[i] = 'x';
    num [++i] = '0';
    while (i >= 0)
        count += ft_putchar_fd(num[i--], fd);
    return (count);
}