# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 18:03:43 by aeid              #+#    #+#              #
#    Updated: 2024/02/29 19:02:59 by aeid             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -L./Printft -lftprintf
RM = rm -f

H_SRC = push_swap.h checker.h get_next_line.h
H_DIR = headers/
H_PATH = $(addprefix $(H_DIR), $(H_SRC))

M_SRC = main.c rotate_cmd.c swap_cmd.c utils.c reverse_r_cmd.c push_cmd.c errors_initializer.c sorting_utils.c sorting.c sorting_utils1.c sorting_utils2.c
M_DIR = mandatory/
M_PATH = $(addprefix $(M_DIR), $(M_SRC))
M_OBJ = $(M_PATH:.c=.o)

U_SRC = ft_split.c ft_substr.c ft_strlen.c ft_strncmp.c
U_DIR = utils/
U_PATH = $(addprefix $(U_DIR), $(U_SRC))
U_OBJ = $(U_PATH:.c=.o)

B_SRC = checker.c ft_split_checker.c ft_substr_checker.c error_checker.c utils_checker.c ft_strlen_checker.c ft_strncmp_checker.c ft_strchr_checker.c
B_DIR = bonus/
B_PATH = $(addprefix $(B_DIR), $(B_SRC))
B_OBJ = $(B_PATH:.c=.o)

G_SRC = get_next_line.c get_next_line_utils.c
G_DIR = get_next_line/
G_PATH = $(addprefix $(G_DIR), $(G_SRC))
G_OBJ = $(G_PATH:.c=.o)

CMD_SRC = push_cmd.c reverse_r_cmd.c rotate_cmd.c swap_cmd.c
CMD_DIR = commands/
CMD_PATH = $(addprefix $(CMD_DIR), $(CMD_SRC))
CMD_OBJ = $(CMD_PATH:.c=.o)

PRINT_DIR = ./Printft

%.o: %.c $(H_PATH) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(M_OBJ) $(U_OBJ)
	make -C $(PRINT_DIR) --no-print-directory
	$(CC) $(CFLAGS) $(M_OBJ) $(U_OBJ) -o $(NAME) $(LFLAGS)

$(BONUS_NAME) : $(G_OBJ) $(CMD_OBJ) $(B_OBJ) 
	make -C $(PRINT_DIR) --no-print-directory
	$(CC) $(CFLAGS) $(G_OBJ) $(CMD_OBJ) $(B_OBJ) -o $(BONUS_NAME) $(LFLAGS)

all: $(NAME)

bonus: $(BONUS_NAME)

clean:
	$(RM) $(U_OBJ)
	$(RM) $(M_OBJ)
	$(RM) $(wildcard $(PRINT_DIR)/*.o)
	$(RM) $(B_OBJ)
	$(RM) $(G_OBJ)
	$(RM) $(CMD_OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	$(RM) $(wildcard $(PRINT_DIR)/*.a)

re: fclean all

.PHONY: all clean fclean re