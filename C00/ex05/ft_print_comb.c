#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	tricky_case(char a, char b, char c)
{
	if (a == '7' && b == '8' && c == '9')
	{
		ft_putchar(a);
		ft_putchar(b);
		ft_putchar(c);
	}
	else if (a != '7' || b != '8' || c != '9')
	{	
		ft_putchar(a);
		ft_putchar(b);
		ft_putchar(c);
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0' - 1;
	while (++a <= '7')
	{
		b = a;
		while (++b <= '8')
		{
			c = b;
			while (++c <= '9')
				tricky_case(a, b, c);
		}
	}
}
