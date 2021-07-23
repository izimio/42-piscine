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

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*tmp;
	unsigned int	i;

	i = -1;
	tmp = begin_list;
	while (++i < nbr)
	{
		if (!tmp)
			return (0);
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		len;
	void	*temp;

	i = -1;
	len = ft_list_size(begin_list);
	while (++i < len / 2)
	{
		temp = ft_list_at(begin_list, i)->data;
		ft_list_at(begin_list, i)->data
		= ft_list_at(begin_list, len - i - 1)->data;
		ft_list_at(begin_list, len - i - 1)->data = temp;
	}
}
