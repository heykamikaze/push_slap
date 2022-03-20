NAME = push_swap
GCC = gcc
CFLAGS = -Wall -Wextra -Werror 
#-fsanitize=address
LIBFT = ./libft/libft.a
LIB_BINARY = -L ./libft -lft 
SRCS = 	main.c \
		operations.c \
		sort_over_five.c \
		sort.c \
		stacks_utils.c \
		args_pars.c \
		lists_utils.c \
		operations_optimization.c \
		score_count.c \
		
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) push_swap.h Makefile
		@$(GCC) $(CFLAGS) $(OBJS) $(LIB_BINARY) -o $(NAME)

$(LIBFT):
		make -C ./libft/

clean:
		rm -f $(OBJS)
		make -C ./libft/ clean

fclean: clean
		rm -f $(NAME)
		make -C ./libft/ fclean

re: fclean all

.PHONY: all clean fclean re
