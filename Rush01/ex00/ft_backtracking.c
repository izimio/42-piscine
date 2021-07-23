#include "ft_includes.h"

int	ft_reset(int **tab, int col, int row, char **views)
{
	if (!tab[3][3] || !ft_check_views(tab, 3, 3, views))
		return (0);
	return (tab[col][row]);
}

void	ft_backtracking(int **tab, char **views
		, int *tab_possibility)
{
	int	j;
	int	row;
	int	col;

	col = -1;
	while (++col < 4)
	{
		row = -1;
		while (++row < 4)
		{
			if (tab[col][row] == 0)
			{
				j = -1;
				tab_possibility = ft_tab_list_possibility(tab, col, row);
				while (++j < ft_count_possibility(tab, col, row))
				{
					tab[col][row] = tab_possibility[j];
					if (ft_check_views(tab, col, row, views))
						ft_backtracking(tab, views, tab_possibility);
					tab[col][row] = ft_reset(tab, col, row, views);
				}
				return ;
			}
		}
	}
}
