/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pos_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:50:48 by maakhan           #+#    #+#             */
/*   Updated: 2024/07/06 19:06:56 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printing(int index, char *array, int fd)
{
	int	count;
	int	checker;

	count = 0;
	while (--index >= 0)
	{
		checker = ft_putchar_fd(array[index], fd);
		if (checker == -1)
			return (-1);
		count += checker;
	}
	return (count);
}

int	ft_putnbr_pos_fd(unsigned long n, int fd)
{
	char	num[10];
	int		i;
	int		count;

	count = 0;
	if (n < 0)
		return (-1);
	if (n == 0)
		return (ft_putchar_fd('0', fd));
	i = 0;
	while (n != 0)
	{
		num[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	return (ft_printing(i, num, fd));
}
