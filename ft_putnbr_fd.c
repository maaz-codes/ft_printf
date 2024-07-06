/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:48:57 by maakhan           #+#    #+#             */
/*   Updated: 2024/07/06 18:49:01 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printing(long temp, char *num, int i, int fd)
{
	int	count;
	int	checker;

	count = 0;
	if (temp < 0)
	{
		count += ft_putchar_fd('-', fd);
		if (count == -1)
			return (-1);
		temp = temp * -1;
	}
	while (temp != 0)
	{
		num[i] = (temp % 10) + '0';
		temp = temp / 10;
		i++;
	}
	while (--i >= 0)
	{
		checker = ft_putchar_fd(num[i], fd);
		if (checker == -1)
			return (-1);
		count += checker;
	}
	return (count);
}

int	ft_putnbr_fd(int n, int fd)
{
	long	temp;
	char	num[10];
	int		i;
	int		count;

	temp = n;
	i = 0;
	if (temp == 0)
		return (ft_putchar_fd('0', fd));
	count = ft_printing(temp, num, i, fd);
	if (count == -1)
		return (-1);
	return (count);
}
