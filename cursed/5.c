#include "ft_list_sort.h"

t_list *ft_list_sort(t_list *lst, int (*cmp)(int, int))
{
	t_list	*begin_list;
	int	temp;

	while (lst->next)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			temp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = temp;
			lst = begin_list;
		}
		else
			lst = lst->next;
	}
	return (begin_list);
}
