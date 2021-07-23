
#include <unistd.h>

int	is_ok(char c, char *str, int index)
{
	int	i;

	i = -1;
	while (++i < index)
		if (str[i] == c)
			return (1);
	return (0);
}

void 	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_union(char *s1, char *s2)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (s1[++i])
	{
		if (is_ok(s1[i], s1, i) == 0)
			ft_putchar(s1[i]);
	}
	while (s2[++j])
	{
		if (is_ok(s2[j], s1, i) == 0 && is_ok(s2[j], s2, j) == 0)
			ft_putchar(s2[j]);
	}
}










void	ft_inter(char *s1, char *s2)
{
	int	tab[255] = {0};

	int	i;
	i = -1;
	while (s2[++i])
	{
		if(tab[(int)s2[i]] == 0)
			tab[(int)s2[i]] = 1;
	}
	i = -1;
	while (s1[++i])
	{
		if(tab[(int)s1[i]] == 1)
		{
			tab[(int)s1[i]] = 2;
			ft_putchar(s1[i]);
		}
	}
}	

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	ft_putchar('\n');
}
