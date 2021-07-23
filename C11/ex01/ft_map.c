#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int	*res;

	i = -1;
	if (length < 1)
		return (NULL);
	res = (int *)malloc(sizeof(int) * length);
	if (!res)
		return (NULL);
	while (++i < length)
		res[i] = f(tab[i]);
	return (res);
}
