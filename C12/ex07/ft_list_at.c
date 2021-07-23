#include "ft_list.h"

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
