# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkhmaruk <dkhmaruk@student.42vienna.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/26 13:44:25 by dkhmaruk          #+#    #+#              #
#    Updated: 2026/06/03 18:11:31 by dkhmaruk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc	
CFLAGS = -Wall -Wextra -Werror -MMD -g

SRC = ft_bzero.c \
	ft_atoi.c \
	ft_clean_all.c \
	ft_split.c \
	check_str.c \
	ft_lstlast.c \
	ft_lstsize.c \
	ft_lstadd_front.c \
	ft_lstadd_back.c \
	ft_lstnew.c \
	ft_printf_fd.c \
	ft_strncmp.c \
	print_op.c \
	print_bench.c \
	main.c \
	manipulation.c \
	small_sort.c \
	simple_sort.c \
	check_flag.c

OBJ_DIR = obj

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
DEP = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
-include $(DEP)
