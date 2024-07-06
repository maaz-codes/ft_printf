/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:50:35 by maakhan           #+#    #+#             */
/*   Updated: 2024/07/06 18:50:43 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int ft_putnbr_hex_fd(unsigned long n, int fd, unsigned int cap)
// {
// 	char	*base;
// 	int		count;
// 	int		checker;

// 	count = 0;
// 	if (cap == 0)
// 		base = "0123456789abcdef";
// 	else
// 		base = "0123456789ABCDEF";
// 	if (n >= 16)
// 	{
// 		checker = ft_putnbr_hex_fd(n / 16, fd, cap);
// 		if (checker == -1)
// 			return (-1);
// 		count += checker;
// 	}
// 	checker = ft_putchar_fd(base[n % 16], fd);
// 	if (checker == -1)
// 		return (-1);
// 	return (count + checker);
// }

static int	ft_printing(int index, char *num, int fd)
{
	int	checker;
	int	count;

	count = 0;
	while (--index >= 0)
	{
		checker = ft_putchar_fd(num[index], fd);
		if (checker == -1)
			return (-1);
		count += checker;
	}
	return (count);
}

int	ft_putnbr_hex_fd(unsigned long n, int fd, unsigned int cap)
{
	char		num[10];
	const char	*hex;
	int			i;

	i = 0;
	if (cap == 1)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n == 0)
		return (ft_putchar_fd('0', fd));
	while (n != 0)
	{
		num[i++] = hex[n % 16];
		n = n / 16;
	}
	return (ft_printing(i, num, fd));
}
