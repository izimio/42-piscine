#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*hex;
	int		tmp;

	i = -1;
	hex = "0123456789abcdef";
	while (str[++i])
	{
		tmp = str[i];
		if (str[i] < 0)
			tmp += 256;
		if (tmp < 32 || tmp > 126)
		{
			ft_putchar('\\');
			ft_putchar(hex[tmp / 16]);
			ft_putchar(hex[tmp % 16]);
		}
		else
			ft_putchar(str[i]);
	}
}
int main()
{
	ft_putstr_non_printable("\t\t\t \v \n \r \f \n 217┘218┌219█ \e coucou");
}
