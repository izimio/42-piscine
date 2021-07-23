#include "ft_list.h"

void	ft_swap_list(t_list	**a, t_list	**b)
{
	void	*tmp;

	tmp = (*a)->data;
	(*a)->data = (*b)->data;
	(*b)->data = tmp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp;
	t_list	*curr;
	int		i;

	i = 1;
	if (!(*begin_list) || !(*begin_list)->next)
		return ;
	while (i)
	{
		i = 0;
		tmp = *begin_list;
		curr = tmp->next;
		while (curr)
		{
			if (cmp(tmp->data, curr->data) > 0)
			{
				ft_swap_list(&tmp, &curr);
				i = 1;
			}
			tmp = tmp->next;
			curr = curr->next;
		}
	}
}
