SRCS =	srcs/ft_algo.c srcs/ft_bsq.c srcs/ft_free_function.c srcs/ft_get_infos.c srcs/ft_parse_map.c srcs/ft_split.c srcs/ft_utils.c srcs/main.c srcs/ft_check_error.c

OBJS = ${SRCS:.c=.o}

HEADER = includes.h

NAME = bsq

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I includes 

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${CFLAGS} ${OBJS}
			${RM} ${OBJS}

all :		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re: fclean all


.PHONY: all clean fclean re
