#ifndef FT_LIST_SORT_H
# define FT_LIST_SORT_H
typedef struct s_list	t_list;
#include <stdlib.h>
#include <stdio.h>
struct	s_list
{
	int	data;
	t_list	*next;
};

#endif
