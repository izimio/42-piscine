#include  <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_tab(int *tab, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		ft_putchar(tab[i] + '0');
	if (tab[0] != 10 - n)
		write (1, ", ", 2);
}

void	ft_print_comb_recursive(int	*tab, int n, int i)
{
	if (i == 0)
		tab[i] = 0;
	else
		tab[i] = tab[i - 1] + 1;
	while (tab[i] < 11 - n + i)
	{
		if (i == n - 1)
			ft_print_tab(tab, n);
		else
			ft_print_comb_recursive(tab, n, i + 1);
		tab[i] = tab[i] + 1;
	}
}	

void	ft_print_combn(int n)
{
	int	tab[10];
	if (n > 0 && n < 10)
		ft_print_comb_recursive(tab, n, 0);
}

int main()
{
	ft_print_combn(8);
}
