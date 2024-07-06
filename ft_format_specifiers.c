/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:15:53 by maakhan           #+#    #+#             */
/*   Updated: 2024/07/06 18:28:10 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_specifiers(int fd, char fs, va_list args)
{
	int	count;

	if (fs == 'c')
		count = ft_putchar_fd((char)va_arg(args, int), fd);
	else if (fs == 's')
		count = ft_putstr_fd(va_arg(args, char *), fd);
	else if (fs == 'd' || fs == 'i')
		count = ft_putnbr_fd(va_arg(args, int), fd);
	else if (fs == 'u')
		count = ft_putnbr_pos_fd(va_arg(args, unsigned int), fd);
	else if (fs == 'x')
		count = ft_putnbr_hex_fd(va_arg(args, unsigned int), fd, 0);
	else if (fs == 'X')
		count = ft_putnbr_hex_fd(va_arg(args, unsigned int), fd, 1);
	else if (fs == '%')
		count = ft_putchar_fd('%', fd);
	else if (fs == 'p')
		count = ft_putadd_fd(va_arg(args, void *), fd);
	else
		count = -1;
	return (count);
}
