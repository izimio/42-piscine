#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_fword(char *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			break ;
		else
			ft_putchar(str[i]);
		i++;
	}
}

int	ft_iblamk(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	ft_lword(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (ft_iblamk(str[i]))
		i--;
	while (str[i] && !ft_iblamk(str[i]))
		i--;
	i++;
	while (str[i] && !ft_iblamk(str[i]))
		ft_putchar(str[i++]);
}

int main(int argc, char **argv)
{
	if(argc == 2)
		ft_lword(argv[1]);
	ft_putchar('\n');
}
