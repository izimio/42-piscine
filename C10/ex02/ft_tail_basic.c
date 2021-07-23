#include "ft_tail.h"

int	ft_file_len(char *str)
{
	int		fd;
	char	c;
	int		i;

	i = 0;
	fd = open(str, O_RDWR);
	while (read(fd, &c, 1) > 0)
		i++;
	close (fd);
	return (i);
}

int	ft_file_newline_len(char *str)
{
	int		fd;
	char	c;
	int		i;

	i = 0;
	fd = open(str, O_RDWR);
	while (read(fd, &c, 1) > 0)
		if (c == '\n')
			i++;
	close (fd);
	return (i);
}

void	ft_print_bytes(int bytes, char *str)
{
	int		i;
	char	c;
	int		fd;

	i = 0;
	fd = open(str, O_RDWR);
	while (read(fd, &c, 1) > 0)
	{
		if (i >= ft_file_len(str) - bytes)
			ft_putchar(c);
		i++;
	}
	close (fd);
}

void	ft_print_last_ten_lines(char	*str)
{
	char	c;
	int		fd;
	int		count;

	count = 0;
	fd = open(str, O_RDWR);
	while (read(fd, &c, 1) > 0)
	{
		if (count >= ft_file_newline_len(str) - 10)
			ft_putchar(c);
		if (c == '\n')
			count++;
	}
	close (fd);
}
