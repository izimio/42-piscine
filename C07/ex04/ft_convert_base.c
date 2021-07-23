#include <stdlib.h>
int	ft_strlen(char *str);
int	check_base(char *base);
int	check(char *base, char c);
int	ft_atoi_base(char *str, char *base);
int	count(long nb, char *base);

char	*ft_malloc_char(long nbr, char *base)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * count(nbr, base) + 1);
	if (!res)
		return (NULL);
	res[count(nbr, base)] = '\0';
	return (res);
}

char	*ft_itoa_base(long nbr, char *base, char *toa)
{
	int		index;
	int		trig;

	trig = 0;
	index = count(nbr, base);
	if (nbr < 0)
	{
		nbr = -nbr;
		trig = 1;
	}
	while (index--)
	{
		toa[index] = base[nbr % ft_strlen(base)];
		nbr /= ft_strlen(base);
	}
	if (trig == 1)
		toa[0] = '-';
	return (toa);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*toa;
	long	nb;

	if (check_base(base_from) != 1 || check_base(base_to) != 1)
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	toa = ft_malloc_char(nb, base_to);
	if (!toa)
		return (NULL);
	toa = ft_itoa_base(nb, base_to, toa);
	return (toa);
}
