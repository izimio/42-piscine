int	ft_iterative_factorial(int nb)
{
	int	i;
	int	res;

	res = 1;
	i = 0;
	if (nb < 0)
		return (0);
	while (++i <= nb)
		res *= i;
	return (res);
}
