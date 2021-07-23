#include <unistd.h>

void	prt_number(int nb)
{
	int	nb1;
	int	nb2;

	nb1 = nb / 10 + 48;
	nb2 = nb % 10 + 48;
	write(1, &nb1, 1);
	write(1, &nb2, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = -1;
	while (++a <= 98)
	{
		b = 0;
		while (++b <= 99)
		{
			if (a < b)
			{
				prt_number(a);
				write(1, " ", 1);
				prt_number(b);
				if (a != 98 || b != 99)
					write(1, ", ", 2);
			}
		}
	}
}
