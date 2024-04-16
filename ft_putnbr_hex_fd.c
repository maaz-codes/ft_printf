#include <unistd.h>
#include "libftprintf.h"

int ft_putnbr_hex_fd(int n, int fd, unsigned int cap)
{
    long temp;
    char num[10];
    char he_X[17] = "0123456789ABCDEF";
	char he_x[17] = "0123456789abcdef";
    int i;
    int count;

    temp = n;
    count = 0;
    if (temp < 0)
    {
        count += ft_putchar_fd('-', fd);
        temp = temp * -1;
    }
    if (temp == 0)
        count += ft_putchar_fd('0', fd);
    i = 0;
    while (temp != 0)
    {
		if (cap == 1)
        	num[i++] = he_X[temp % 16];
		else
			num[i++] = he_x[temp % 16];
        temp = temp / 16;
    }
    while (--i >= 0)
        count += ft_putchar_fd(num[i], 1);
    return count;
}