/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:49:25 by maakhan           #+#    #+#             */
/*   Updated: 2024/07/06 18:49:26 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checker(char c, char next_c, va_list args, int fd)
{
	int	count;
	int	checker;

	count = 0;
	if (c == '%')
	{
		checker = ft_format_specifiers(fd, next_c, args);
		if (checker == -1)
			return (-1);
		count += checker;
	}
	else
	{
		checker = ft_putchar_fd(c, fd);
		if (checker == -1)
			return (-1);
		count += checker;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		checker;
	int		fd;

	va_start(args, str);
	count = 0;
	i = 0;
	fd = 1;
	while (str[i])
	{
		checker = ft_checker(str[i], str[i + 1], args, fd);
		if (checker == -1)
			return (-1);
		count += checker;
		if (str[i] == '%')
			i++;
		i++;
	}
	va_end(args);
	return (count);
}

// int main()
// {
// 	char *name = NULL;

// 	int my_count = ft_printf("\001\002\007\v\010\f\r\n");
// 	int count = printf("\001\002\007\v\010\f\r\n");
// 	printf("my_count = %d || count = %d \n", my_count, count);
// }
// count = ft_printf("%X\n", 255);
// printf("Count = %d \n", count);

// count = ft_printf("%d%%\n", 98);
// printf("Count = %d \n", count);

// count = ft_printf("%o \n", 200);
// printf("Count = %d \n", count);

// count = ft_printf("%x\n", -1);
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
