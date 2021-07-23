#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_params(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (++i < argc)
	{
		j = i;
		while (j < argc - i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) < 0)
			{
				tmp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = tmp;
				j = 1;
			}
			else
				j++;
		}
	}
}

int	main(int argc, char **argv)
{
	ft_sort_params(argc, argv);
	while (argc-- > 1)
	{
		ft_putstr(argv[argc]);
		ft_putstr("\n");
	}
}
