#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list args;
	va_start(args, str);
	int i;
	int count = 0;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			count += ft_format_specifiers(str[++i], args);
		else
			count += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

int main() 
{
	char *name = NULL;
	int count;

	count = ft_printf("%x\n", -1);
	printf("Count = %d \n", count);
}
	// count = ft_printf("%X\n", 255);
	// printf("Count = %d \n", count);
	// count = ft_printf("%d%%\n", 98);
	// printf("Count = %d \n", count);
	// count = ft_printf("%p\n", 200);
	// printf("Count = %d \n", count);
	// count = ft_printf("%o \n", 200);
	// printf("Count = %d \n", count);



	// count = ft_printf("%c\n", 'M');
	// printf("Count = %d \n", count);
	// count = ft_printf("Hi %s\n", name);
	// printf("Count = %d \n", count);
	// count = ft_printf("%d\n", 45);
	// printf("Count = %d \n", count);
	// count = ft_printf("%i\n", 34);
	// printf("Count = %d \n", count);
	// count = ft_printf("%u\n", 20);
	// printf("Count = %d \n", count);

// %c Prints a single character.
// •%s Prints a string (as defined by the common C convention).
// •%d Prints a decimal (base 10) number.
// •%i Prints an integer in base 10.
// •%u Prints an unsigned decimal (base 10) number.
// •%x Prints a number in hexadecimal (base 16) lowercase format.
// •%X Prints a number in hexadecimal (base 16) uppercase format.
// •%% Prints a percent sign.
// •%p The void * pointer argument has to be printed in hexadecimal format.

