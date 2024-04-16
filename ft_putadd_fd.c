#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int ft_putadd_fd(void *add, int fd)
{
    int x;
    int count;
    unsigned long address;

    count = 0;
    address = (unsigned long)add;
    count = ft_putstr_fd("0x", fd);
    if (count == -1)
        return (-1);
    x = ft_putnbr_hex_fd(address, fd, 0);
    if (x == -1)
        return (-1);
    return (count + x);
}