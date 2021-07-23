int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
			return (0);
	return (1);
}
