/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:50:35 by maakhan           #+#    #+#             */
/*   Updated: 2024/07/06 19:59:30 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_fd(unsigned long n, int fd, unsigned int cap)
{
	char	*hex;
	int		count;
	int		checker;

	count = 0;
	if (cap == 0)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		checker = ft_putnbr_hex_fd(n / 16, fd, cap);
		if (checker == -1)
			return (-1);
		count += checker;
	}
	checker = ft_putchar_fd(hex[n % 16], fd);
	if (checker == -1)
		return (-1);
	return (count + checker);
}
