#include <unistd.h>
#include "libftprintf.h"

int ft_putstr_fd(char *s, int fd)
{
    int i;
	int count;

    i = 0;
	count = i;
    while (s[i] != '\0')
    {
		count += ft_putchar_fd(s[i], fd);
        i++;
    }
	if (count != i)
		return (-1);
	return (count);
}