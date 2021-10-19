NAME	= libft.a

HEADER = libft.h

SRCS	= ft_strlen.c ft_isdigit.c ft_split.c ft_strlcpy.c

OBJS	= ${SRCS:.c=.o}

CC			= gcc
RM			= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:	
		 	${CC} ${CFLAGS} -g -c $< -o $@

$(NAME):	${OBJS} 
					ar rcs ${NAME} $?
		
all:		${NAME} ${HEADER} 

clean:
					${RM} ${OBJS}

fclean:		clean
					${RM} ${NAME}

re:					fclean all

.PHONY:		all clean fclean re bonus