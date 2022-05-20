NAME_A = push_swap
NAME_B = checker
GCC = gcc
CFLAGS = -Wall -Wextra -Werror 
LIBFT = ./libft/libft.a
LIB_BINARY = -L ./libft -lft 
SRCS_A = 	main.c \
		operations.c \
		sort_over_five.c \
		sort.c \
		stacks_utils.c \
		args_pars.c \
		lists_utils.c \
		operations_optimization.c \
		score_count.c \
		
SRCS_B =	checker_mine.c \
		operations.c \
		sort_over_five.c \
		sort.c \
		stacks_utils.c \
		args_pars.c \
		lists_utils.c \
		operations_optimization.c \
		score_count.c \
		checker_commands.c \
		check_utils.c

OBJS_A = $(SRCS_A:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

all: $(NAME_A)

$(NAME_A): $(OBJS_A) $(LIBFT) push_swap.h Makefile
		@$(GCC) $(CFLAGS) $(OBJS_A) $(LIB_BINARY) -o $(NAME_A)

all: $(NAME_B)

$(NAME_B): $(OBJS_B) $(LIBFT) push_swap.h Makefile
		@$(GCC) $(CFLAGS) $(OBJS_B) $(LIB_BINARY) -o $(NAME_B)

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
