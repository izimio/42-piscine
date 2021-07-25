#include "includes.h"

int	**ft_fill_tab(char *str, int **nb_tab);
int	**ft_init_tab(int size);
int	ft_tab_size(char *str);

int	**ft_atoi(char *str)
{
	int	**nb_tab;
	int	i;
	int	size;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] == '0' && str[i + 1] != '\0')
		i++;
	size = ft_tab_size(&str[i]);
	nb_tab = ft_init_tab(size);
	if (!nb_tab)
		return (NULL);
	nb_tab = ft_fill_tab(&str[i], nb_tab);
	return (nb_tab);
}

int	**ft_fill_tab(char *str, int **nb_tab)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb_tab[0][i] = str[i] - '0';
		j = i;
		while (j > 0)
		{
			nb_tab[1][j - 1] += 1;
			j--;
		}
		i++;
	}
	return (nb_tab);
}

int	**ft_init_tab(int size)
{
	int	i;
	int	**nb_tab;

	i = 0;
	nb_tab = malloc (2 * sizeof(int *));
	if (!nb_tab)
		return (NULL);
	nb_tab[0] = malloc (sizeof(int) * (size + 1));
	nb_tab[1] = malloc (sizeof(int) * (size + 1));
	if (!nb_tab[0] || !nb_tab[1])
		return (NULL);
	while (i < size)
	{
		nb_tab[0][i] = 0;
		nb_tab[1][i] = 0;
		i++;
	}
	nb_tab[0][i] = -1;
	nb_tab[1][i] = -1;
	return (nb_tab);
}

int	ft_tab_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}
