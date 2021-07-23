#include <stdlib.h>
int	*ft_rrange(int min, int max)
{
	int	*tab;
	int	i;

	i = 0;
	if (min == max)
	{
		tab = (int *)malloc(sizeof(int));
		tab[0] = min;
	}
	if (min < max)
		tab = (int *)malloc(sizeof(int) * (max - min));
	else
		tab = (int *)malloc(sizeof(int) * (min - max));
	while (min != max)
	{
		tab[i++] = min;
		if (min < max)
			min++;
		else
			min--;
	}
	return (tab);
}

int main()
{

	int	*tab;
	int	i;

	i = -1;
	tab = ft_rrange(-5,-10);
	while (++i < 6)
		printf("%d\n",tab[i]);
}
