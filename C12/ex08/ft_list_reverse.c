#include "ft_list.h"
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*next;
	t_list	*previous;
	t_list	*atm;

	next = NULL;
	previous = NULL;
	atm = *begin_list;
	while (atm)
	{
		next = atm->next;
		atm->next = previous;
		previous = atm;
		atm = next;
	}
	*begin_list = previous;
}
