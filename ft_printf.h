/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maakhan <maakhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 18:49:33 by maakhan           #+#    #+#             */
/*   Updated: 2024/07/06 19:52:29 by maakhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putnbr_pos_fd(unsigned long n, int fd);
int	ft_putnbr_hex_fd(unsigned long n, int fd, unsigned int cap);
int	ft_format_specifiers(int fd, char fs, va_list args);
int	ft_putadd_fd(void *add, int fd);

#endif