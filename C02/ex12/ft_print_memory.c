#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

void	print_adresse(long int addr)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (addr < 0)
		ft_putchar('.');
	if (addr > 15)
	{
		print_adresse(addr / 16);
	}
	ft_putchar(hex[addr % 16]);
}

void	ft_print_line_hex(void *addr, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size)
	{
		tmp = *(char *)(addr + i);
		if (tmp < 16)
			ft_putchar('0');
		print_adresse(tmp);
		if (i % 2 == 1)
			ft_putchar(' ');
		i++;
	}
	while (i < 16)
	{
		ft_putstr("  ");
		if (i % 2 == 1)
			ft_putchar(' ');
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				j;

	i = 0;
	while (i < size)
	{
		j = *(char *)(addr + i);
		if (i % 16 == 0)
		{
			ft_putstr("0000000");
			print_adresse((long)addr + i);
			ft_putstr(": ");
			if (size - i > 15)
				ft_print_line_hex(addr + i, 16);
			else
				ft_print_line_hex(addr + i, size - i);
		}
		if (j > 31 && j < 127)
			ft_putchar(*(char *)(addr + i));
		else
			ft_putchar('.');
		if (++i % 16 == 0 || i == size)
			ft_putchar('\n');
	}
	return (addr);
}

int main()
{
	char str[] = "coucou les amimch c'est fou tout ce quon peut f aire avec print memorry";
	ft_print_memory(str,64);
}
