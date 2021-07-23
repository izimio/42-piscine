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
	if (ft_strlen(base) <= 1)
		return (-1);
	while (base[++i])
	{
		j = -1;
		count = 0;
		if (base[i] == '-' || base[i] == '+'
			|| base[i] <= 32 || base[i] == 127)
			return (-1);
		while (base[++j])
			if (base[j] == base[i])
				count++;
		if (count >= 2)
			return (-1);
	}
	return (1);
}

int	check(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	long int	res;
	int			i;
	int			neg;

	neg = 1;
	i = 0;
	res = 0;
	if (check_base(base) != 1)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] && check(base, str[i]) != -1)
	{
		res = res * ft_strlen(base) + check(base, str[i]);
		i++;
	}
	return (res * neg);
}
