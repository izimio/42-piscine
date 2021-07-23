#include "includes.h"

int	ft_calc(int a, int b, int sign)
{
	if (sign == 0)
		return (a + b);
	if (sign == 1)
		return (a - b);
	if (sign == 2)
		return (a / b);
	if (sign == 3)
		return (a * b);
	if (sign == 4)
		return (a % b);
	return (0);
}

int	main(int argc, char **argv)
{
	int	nb1;
	int	nb2;
	int	sign;

	if (argc == 4)
	{
		nb1 = ft_atoi(argv[1]);
		nb2 = ft_atoi(argv[3]);
		sign = ft_operator(argv[2]);
		if (sign == 2 && nb2 == 0)
		{
			write(1, "Stop : division by zero\n", 24);
			return (0);
		}
		if (sign == 4 && nb2 == 0)
		{
			write(1, "Stop : modulo by zero\n", 22);
			return (0);
		}
		ft_putnbr(ft_calc(nb1, nb2, sign));
		ft_putchar('\n');
	}
	return (0);
}
