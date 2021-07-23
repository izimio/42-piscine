int	count_letter(int	nbr)
{
	long	nb;
	int	i;

	i = 0;
	nb = nbr;
	if (nb <= 0)
	{
		i++;
		nb = -nb;
	}
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}


#include <stdlib.h>

char	*ft_itoa(int	nbr)
{
	long	nb;
	int	i;
	char	*toa;
	int	len;

	len = count_letter(nbr);
	nb = nbr;
	i = 0;
	toa = (char *)malloc(sizeof(char) * len + 1);
	toa[len + 1] = '\0';
	if (nb == 0)
	{
		toa[0] = '0';
		return (toa);
	}
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	len--;
	while (nb > 0)
	{
		toa[len--] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (i == 1)
		toa[0] = '-';
	return (toa);
}
int main()
{
	printf("%s",ft_itoa(-2147483648));
}
