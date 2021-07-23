#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *base)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	j = -1;
	count = 0;
	while (base[++i])
	{
		while (base[++j])
		{
			if (base[j] == base[i])
			{
				count++;
				if (count == 2 || base[i] == '+' || base[i] == '-')
					return (0);
			}
		}
		j = 0;
		count = 0;
	}
	return (i > 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long		nb;
	int			len;

	nb = nbr;
	len = ft_strlen(base);
	if (check_base(base) == 1)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = nb * -1;
		}
		if (nb >= len)
			ft_putnbr_base(nb / len, base);
		ft_putchar(base[nb % len]);
	}
}
