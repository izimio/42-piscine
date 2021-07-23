int	ft_check_rowup_view(int **tab, int row, int col, char **views)
{
	int	i;
	int	nb_max;
	int	checkview;
	int	must_equal;

	i = 0;
	nb_max = 0;
	checkview = 0;
	must_equal = 0;
	while (i < 4)
	{
		if (row == 3)
			must_equal = 1;
		if (tab[i][col] > nb_max)
		{
			checkview++;
			nb_max = tab[i][col];
		}
		i++;
	}
	return ((!must_equal && checkview <= (views[col][0] - '0'))
			|| (must_equal && checkview == (views[col][0] - '0')));
}

int	ft_check_colleft_view(int **tab, int row, int col, char **views)
{
	int	i;
	int	nb_max;
	int	checkview;
	int	must_equal;

	i = 0;
	nb_max = 0;
	checkview = 0;
	must_equal = 0;
	while (i < 4)
	{
		if (col == 3)
			must_equal = 1;
		if (tab[row][i] > nb_max)
		{
			checkview++;
			nb_max = tab[row][i];
		}
		i++;
	}	
	return ((!must_equal && checkview <= (views[8 + row][0] - '0'))
			|| (must_equal && checkview == (views[8 + row][0] - '0')));
}

int	ft_check_rowdown_view(int **tab, int col, char **views)
{
	int	i;
	int	nb_max;
	int	checkview;

	i = 3;
	nb_max = 0;
	checkview = 0;
	while (i >= 0)
	{
		if (tab[i][col] > nb_max)
		{
			checkview++;
			nb_max = tab[i][col];
		}
		i--;
	}
	return (checkview == (views[4 + col][0] - '0'));
}

int	ft_check_colright_view(int **tab, int row, char **views)
{
	int	i;
	int	nb_max;
	int	checkview;

	i = 3;
	nb_max = 0;
	checkview = 0;
	while (i >= 0)
	{
		if (tab[row][i] != 0 && tab[row][i] > nb_max)
		{
			checkview++;
			nb_max = tab[row][i];
		}
		i--;
	}
	return (checkview == (views[12 + row][0] - '0'));
}

int	ft_check_views(int **tab, int row, int col, char **views)
{
	int	up_left;
	int	down;
	int	right;

	up_left = 1;
	down = 1;
	right = 1;
	if (!ft_check_rowup_view(tab, row, col, views)
		|| !ft_check_colleft_view(tab, row, col, views))
		up_left = 0;
	if (col == 3)
	{
		if (!ft_check_colright_view(tab, row, views))
			right = 0;
	}
	if (row == 3)
	{
		if (!ft_check_rowdown_view(tab, col, views))
			down = 0;
	}
	return (up_left && down && right);
}
