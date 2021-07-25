#include "includes.h"

void	ft_free_t_elem(t_elem	*tab)
{
	int	i;

	i = 0;
	while (tab[i].power != -1)
		free(tab[i++].value);
	free (tab);
}

void	ft_free_char(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free (res);
}

void	ft_free_int(int **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
}
