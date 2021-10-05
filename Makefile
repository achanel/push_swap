NAME	= push_swap

LIBRARY	= -lft -L$(LIBFT_DIRECTORY)

INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)

HEADERS_LIST = push_swap.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SRCS_DIRECTORY = ./src/
SRCS_LIST	= push_swap.c do_swap.c do_push.c do_rotate.c do_check.c short_solver.c utils.c stack_utils.c\
				number_utils.c steps_counter.c solver.c do_big_small.c
SRCS = $(addprefix $(SRCS_DIRECTORY), $(SRCS_LIST))

OBJS_DIRECTORY = objects/
OBJS_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJS = $(addprefix $(OBJS_DIRECTORY), $(OBJS_LIST))

CC			= gcc

# CFLAGS	= -Wall -Wextra -Werror -g #del -g
CFLAGS	= -g

all:		${NAME}

$(NAME):	$(LIBFT) $(OBJS_DIRECTORY) $(OBJS)
			@$(CC) $(CFLAGS) $(LIBRARY) $(INCLUDES) $(OBJS) -o $(NAME)

$(OBJS_DIRECTORY):
			mkdir -p $(OBJS_DIRECTORY)

$(OBJS_DIRECTORY)%.o : $(SRCS_DIRECTORY)%.c $(HEADERS)
			@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
			@$(MAKE) -sC $(LIBFT_DIRECTORY)
		
clean:
			@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
			@rm -rf $(OBJS_DIRECTORY)

fclean:		clean
			@rm -f $(LIBFT)
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus