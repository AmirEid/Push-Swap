# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 18:12:48 by aeid              #+#    #+#              #
#    Updated: 2023/11/23 19:04:48 by aeid             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_pointer.c ft_printf.c ft_putchar.c ft_puthex.c ft_putunsigned.c ft_itoa.c
OBJS = $(SOURCES:.c=.o)
COMPILER = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(COMPILER) -c $(CFLAGS) $?

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re