int	ft_str_is_printable(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!(str[i] >= 32 && str[i] <= 126))
			return (0);
	return (1);
}
