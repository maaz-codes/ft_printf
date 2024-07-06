/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:49:25 by maakhan           #+#    #+#             */
/*   Updated: 2024/07/06 19:04:38 by maakhan          ###   ########.fr       */
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
