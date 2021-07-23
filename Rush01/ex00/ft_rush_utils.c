#include "ft_includes.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		ft_putchar(s[i]);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_free_tab(int	**tab, char **views)
{
	int	j;

	j = -1;
	while (++j < 4)
		free(tab[j]);
	free(tab);
	j = -1;
	while (++j < 17)
		free(views[j]);
	free(views);
}

int	ft_count_possibility(int **tab, int col, int row)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (++i <= 4)
	{
		if (ft_possibility(tab, i, col, row) == 1)
			count++;
	}
	return (count);
}
