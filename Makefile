# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schancho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 15:37:47 by schancho          #+#    #+#              #
#    Updated: 2021/03/04 15:37:51 by schancho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1 = push_swap
NAME_2 = checker

CC = gcc  -g -fsanitize=address -g3
CFLAGS = #-Wall -Wextra -Werror 

SRC_PS = ./push_swap_src/file1.c \
		./push_swap_src/file3.c  \
		./push_swap_src/file4.c \
		./push_swap_src/file2.c \
		./push_swap_src/file5.c \
		./push_swap_src/file6.c \
		./push_swap_src/file7.c \
		./push_swap_src/push_swap.c

SRC_CH = ./checker_src/checker.c \
		./checker_src/checker1.c \
		./checker_src/checker2.c

SRC    = ft_atoi.c \
		op1.c \
		op2.c \
		op3.c \
		stack_state.c \
		utils.c

OBJ = .c=.o

all: $(NAME_1)

$(NAME_1):
	
	@$(CC) $(CFLAGS) $(SRC_PS) $(SRC)  -o $(NAME_1) 

bonus : $(NAME_2)

$(NAME_2):
	@$(CC) $(CFLAGS) $(SRC_CH) $(SRC)  -o $(NAME_2)

fclean: 
	@rm -rf $(NAME_1) $(NAME_2) 

re: fclean all
