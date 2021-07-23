void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = -1;
	while (++i < --size)
	{
		tmp = tab[i];
		tab[i] = tab[size];
		tab[size] = tmp;
	}
}
