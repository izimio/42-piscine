#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*elem;

	elem = begin_list;
	i = 0;
	while (elem != NULL)
	{
		elem = elem->next;
		i++;
	}
	return (i);
}
