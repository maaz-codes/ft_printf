NAME	= libftprintf.a

SRCS	= ft_printf.c ft_putadd_fd.c ft_putchar_fd.c ft_putnbr_fd.c ft_putnbr_hex_fd.c ft_putnbr_pos_fd.c ft_putstr_fd.c ft_format_specifiers.c

OBJS	= $(SRCS:.c=.o)

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all