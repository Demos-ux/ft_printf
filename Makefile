# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsisli <dsisli@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/26 17:43:43 by dsisli            #+#    #+#              #
#    Updated: 2025/10/30 15:15:50 by dsisli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

flags = -Wall -Wextra -Werror

CC = cc

ar = ar rcs

srcs = ft_printf.c \
	ft_formatchecker.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_putstr.c \
	ft_puthex.c \
	ft_putbhex.c \
	ft_putpercent.c \
	ft_putpointer.c

obj = $(srcs:.c=.o)

all: $(NAME)

$(NAME): $(obj)
	$(ar) $(NAME) $(obj)

clean:
	rm -f $(obj)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

%.o: %.c ft_printf.h
	$(CC) $(flags) -c $< -o $@
