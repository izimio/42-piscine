SRCS =	do_op.c do_op_functions.c 

OBJS = ${SRCS:.c=.o}

HEADER = includes.h

NAME = do-op

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
