#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>

int ft_printf(const char *str, ...);
int ft_putchar_fd(char c, int fd);
int ft_putstr_fd(char *s, int fd);
int ft_putnbr_fd(int n, int fd);
int ft_putnbr_pos_fd(unsigned long n, int fd);
int ft_putnbr_hex_fd(unsigned long n, int fd, unsigned int cap);
int ft_format_specifiers(char fs, va_list args);
int ft_putadd_fd(unsigned long n, int fd);

#endif