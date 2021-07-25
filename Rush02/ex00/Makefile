SRCS = ft_atoi.c ft_check_error.c ft_free_functions.c ft_parse.c ft_print_nb.c ft_rush_02_utils.c ft_split.c ft_tab.c ft_tab_utils.c main.c ft_parse_dictionnary.c

OBJS = ${SRCS:.c=.o}

HEADER = includes.h

NAME = rush-02

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I includes 

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${CFLAGS} ${OBJS}
			chmod 444 numbers.dict


all :		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re: fclean all


.PHONY: all clean fclean re
