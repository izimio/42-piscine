#include "ft_includes.h"

int	**ft_tab_init(void)
{
	int		row;
	int		col;
	int		**tab;

	row = 0;
	col = 0;
	tab = (int **) malloc(4 * sizeof(int *));
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			tab[row] = (int *) malloc(4 * sizeof(int));
			tab[row][col] = 0;
			col++;
		}
		row++;
	}
	return (tab);
}

void	ft_print_tab(int **tab)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	col = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			c = tab[row][col] + '0';
			write(1, &c, 1);
			if (col < 3)
				write(1, " ", 1);
			col++;
		}
		write (1, "\n", 1);
		row++;
	}
}

int	ft_possibility(int **tab, int nb, int col, int row)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (nb == tab[col][i])
			return (0);
	i = -1;
	while (++i < 4)
		if (nb == tab[i][row])
			return (0);
	return (1);
}

int	*ft_tab_list_possibility(int **tab, int col, int row)
{
	int	*new_tab;
	int	i;
	int	count;
	int	j;

	j = 0;
	i = 0;
	count = 0;
	while (++i <= 4)
	{
		if (ft_possibility(tab, i, col, row) == 1)
			count++;
	}
	new_tab = (int *)malloc(sizeof(int ) * count);
	if (!new_tab)
		return (NULL);
	i = -1;
	while (++j <= 4)
	{
		if (ft_possibility(tab, j, col, row) == 1)
			new_tab[++i] = j;
	}
	return (new_tab);
}
