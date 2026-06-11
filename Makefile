NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	validate_inputs.c \
	parse_inputs.c \
	split_whitespace.c \
	push_swap_utils.c \
	options.c \
	stack_utils.c \
	stack_build.c \
	disorder.c \
	print.c \
	operations_swap_push.c \
	operations_push_extra.c \
	operations_rotate.c \
	operations_reverse_rotate.c \
	sort_small.c \
	sort_simple.c \
	sort_medium.c \
	sort_complex.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
