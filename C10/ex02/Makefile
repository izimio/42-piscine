SRCS =	ft_tail_basic.c  ft_tail_utils.c ft_tail.c

OBJS = ${SRCS:.c=.o}

HEADER = ft_tail.h

NAME = ft_tail

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I includes 

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${CFLAGS} ${OBJS}

all :		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re: fclean all


.PHONY: all clean fclean re
