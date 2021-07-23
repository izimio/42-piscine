#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_absolute(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

void	ft_solve(char *tab, int nbq, int *res)
{
	int	i;
	int	j;

	if (nbq == 10)
	{
		nbq = 0;
		while (nbq < 10)
			ft_putchar(tab[nbq++] + '0');
		ft_putchar('\n');
		(*res)++;
		return ;
	}
	i = -1;
	while (++i < 10)
	{	
		j = 0;
		while (j < nbq && i != tab[j] && ft_absolute(tab[j] - i) != nbq - j)
			j++;
		if (j >= nbq)
		{
			tab[nbq] = i;
			ft_solve(tab, nbq + 1, res);
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		nbq;
	char	tab[10];
	int		res;

	nbq = 0;
	res = 0;
	ft_solve(tab, nbq, &res);
	return (res);
}
