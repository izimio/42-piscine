int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		return (0);
	if (nb == 1)
		return (1);
	while (++i < nb / 2 && i < 46341)
	{
		if (i * i == nb)
		{
			if (nb % i == 0)
				return (i);
			else
				return (0);
		}
	}
	return (0);
}
