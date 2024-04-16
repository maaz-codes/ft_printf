#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

// int ft_putnbr_hex_fd(int n, int fd, unsigned int cap)
// int	ft_putnbr_hex_fd(unsigned long n, int fd, int cap)
// {
// 	char	*base;
// 	int		count;
// 	int		x;

// 	count = 0;
// 	if (cap == 0)
// 		base = "0123456789abcdef";
// 	else
// 		base = "0123456789ABCDEF";
// 	if (n >= 16)
// 	{
// 		x = ft_putnbr_hex_fd(n / 16, fd, cap);
// 		if (x == -1)
// 			return (-1);
// 		count += x;
// 	}
// 	x = ft_putchar_fd(base[n % 16], fd);
// 	if (x == -1)
// 		return (x);
// 	return (count + x);
// }

// int ft_putnbr_hex_fd(unsigned long n, int fd, unsigned int cap) {
//     char num[20];
//     const char *hex;
//     int i = 0;
//     int count = 0;

//     if (cap == 1)
//         hex = "0123456789ABCDEF";
//     else
//         hex = "0123456789abcdef";

//     if (n == 0) {
//         count += ft_putchar_fd('0', fd);
//         return count; // Return count for '0'
//     }

//     if ((long)n < 0) {
//         count += ft_putchar_fd('-', fd); // Print negative sign
//         n = -n; // Make n positive
//     }

//     while (n != 0) {
//         num[i++] = hex[n % 16];
//         n = n / 16;
//         count++; // Increment count for each digit printed
//     }

//     while (--i >= 0)
//         count += ft_putchar_fd(num[i], fd);

//     return count; // Return total count of characters printed
// }


int ft_putnbr_hex_fd(unsigned long n, int fd, unsigned int cap)
{
    char num[20];
    const char *hex;
    int i;
    int count;

    count = 0;
    i = 0;
    if (cap == 1)
        hex = "0123456789ABCDEF";
    else
        hex = "0123456789abcdef";
    if ((long)n < 0)
    {
        n = -n;
    }
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