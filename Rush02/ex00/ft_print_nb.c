#include "includes.h"

int		ft_print_str(int nb, int power, t_elem *dict, int sep);
void	ft_print_final(int **nb_tab, t_elem *dict);
int		ft_print_tenth(int **nb_tab, int i, t_elem *dict, int start);
int		ft_triple_isempty(int *nb_tab, int i);

void	ft_print_final(int **nb_tab, t_elem *dict)
{
	int		i;
	int		start;

	i = 0;
	start = 0;
	if (nb_tab[0][0] == 0 && nb_tab[1][0] == 0)
		ft_print_str(0, 0, dict, 0);
	while (nb_tab[1][i] != -1 && (nb_tab[0][0] != 0))
	{
		if (nb_tab[1][i] % 3 == 0)
		{
			if (i - 2 >= 0 && nb_tab[0][i - 2] != 0)
			{
				ft_print_str(nb_tab[0][i - 2], 0, dict, start);
				ft_print_str(10, 2, dict, 1);
				start = 1;
			}
			start = ft_print_tenth(nb_tab, i, dict, start);
			if (!ft_triple_isempty(nb_tab[0], i) && nb_tab[1][i])
				ft_print_str(10, nb_tab[1][i], dict, start);
		}
		i++;
	}
	write (1, "\n", 1);
	ft_free_int(nb_tab, 2);
}

int	ft_print_tenth(int **nb_tab, int i, t_elem *dict, int start)
{
	int	tenth;

	tenth = 0;
	if (i - 1 >= 0)
		tenth = nb_tab[0][i - 1] * 10;
	tenth += nb_tab[0][i];
	if (tenth >= 11 && tenth <= 19)
	{
		ft_print_str(tenth, 0, dict, start);
		start = 1;
	}
	else
	{
		if (i - 1 >= 0 && nb_tab[0][i - 1] != 0)
		{
			ft_print_str(nb_tab[0][i - 1] * 10, 0, dict, start);
			start = 1;
		}
		if (nb_tab[0][i] != 0)
		{
			ft_print_str(nb_tab[0][i], 0, dict, start);
			start = 1;
		}
	}
	return (start);
}

int	ft_is_printable(int **tab)
{
	int	i;
	int	power_max;

	i = 0;
	power_max = 36;
	if (tab[1][0] > (power_max + 2))
		return (0);
	return (1);
}

int	ft_print_str(int nb, int power, t_elem *dict, int sep)
{
	int	i;

	i = 0;
	while (dict[i].power != -1)
	{
		if (dict[i].key == nb && dict[i].power == power)
		{	
			if (sep == 1)
				write(1, " ", 1);
			ft_putstr(dict[i].value);
			return (0);
		}
		i++;
	}
	return (-1);
}

int	ft_triple_isempty(int *nb_tab, int i)
{
	if (i - 2 >= 0 && nb_tab[i - 2])
		return (0);
	if (i - 1 >= 0 && nb_tab[i - 1])
		return (0);
	if (nb_tab[i])
		return (0);
	return (1);
}
