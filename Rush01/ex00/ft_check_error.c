#include "ft_includes.h"

int	ft_check_error(char *str)
{
	int	i;
	int	count;
	int	space;

	i = 0;
	count = 0;
	space = 0;
	while ((str[i] >= '1' && str[i] <= '4') || str[i] == ' ')
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			i++;
			count++;
		}
		else
			return (0);
		if (str[i] == ' ')
		{
			i++;
			space++;
		}
		else if (str[i] != ' ' && count != 16)
			return (0);
	}
	return (count == 16 && space == 15);
}

int	ft_is_solvable(int	**tab)
{
	int	i;
	int	j;

	j = -1;
	i = -1;
	while (++j < 4)
	{
		while (++i < 4)
			if (tab[j][i] == 0)
				return (0);
	}
	return (1);
}
