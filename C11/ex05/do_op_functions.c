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

void	ft_putnbr(int nb)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar('-');
		nbr = -nb;
	}
	else
		nbr = nb;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

int	ft_atoi(char *str)
{
	int		i;
	long	nb;
	int		neg;

	neg = 1;
	i = 0;
	nb = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * neg);
}

int	ft_operator(char *str)
{
	int	i;

	if (ft_strlen(str) > 1)
		return (-5);
	i = 0;
	if (str[i] == '+')
		return (0);
	if (str[i] == '-')
		return (1);
	if (str[i] == '/')
		return (2);
	if (str[i] == '*')
		return (3);
	if (str[i] == '%')
		return (4);
	return (-5);
}
