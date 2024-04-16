#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>

int ft_putchar_fd(char c, int fd);
int ft_putstr_fd(char *s, int fd);
int ft_putnbr_fd(int n, int fd);
int ft_putnbr_pos_fd(unsigned int n, int fd);
int ft_putnbr_hex_fd(int n, int fd, unsigned int cap);
int ft_format_specifiers(char fs, va_list args);
int ft_putadd_fd(int n, int fd);

#endif