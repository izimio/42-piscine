#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_chr_is_alpha(char c)
{
	if((c >= 'a' && c <= 'z'))
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (2);
	return (0);
}

void	ft_roton_13(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_chr_is_alpha(str[i]) == 1)
		{
			if (str[i] < 'n')
				ft_putchar(str[i] + 13);
			else
				ft_putchar(str[i] - 13);
		}
		else if (ft_chr_is_alpha(str[i]) == 2)
		{
			if (str[i] < 'N')
				ft_putchar(str[i] + 13);
			else
				ft_putchar(str[i] - 13);
		}
		else
			ft_putchar(str[i]);
	}
}

int main(int argc, char **argv)
{
	if(argc == 2)
		ft_roton_13(argv[1]);
	ft_putchar('\n');
}

