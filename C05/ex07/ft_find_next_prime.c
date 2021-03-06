int	ft_is_prime(int nb)
{
	int	i;

	i = 1;
	if (nb <= 1)
		return (0);
	while (i < nb - 1 && i < 46341)
		if (nb % ++i == 0)
			return (0);
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 1)
		return (2);
	while (ft_is_prime(nb) != 1)
		nb++;
	return (nb);
}
