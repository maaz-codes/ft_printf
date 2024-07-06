/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 17:26:35 by maakhan           #+#    #+#             */
/*   Updated: 2024/07/06 18:59:17 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadd_fd(void *add, int fd)
{
	int				checker;
	int				count;
	unsigned long	address;

	count = 0;
	address = (unsigned long)add;
	count = ft_putstr_fd("0x", fd);
	if (count == -1)
		return (-1);
	checker = ft_putnbr_hex_fd(address, fd, 0);
	if (checker == -1)
		return (-1);
	return (count + checker);
}
