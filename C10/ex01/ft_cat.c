#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <libgen.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		ft_putchar(s[i]);
}

void	ft_useless(char **argv, int i)
{
	ft_putstr(basename(argv[0]));
	ft_putstr(": ");
	ft_putstr(argv[i]);
}

int	main(int argc, char **argv)
{
	int		file;
	char	c;
	int		i;

	i = 0;
	if (argc == 1)
		while (read(0, &c, 1) > 0)
			ft_putchar(c);
	while (++i < argc)
	{
		file = open(argv[i], O_RDWR);
		if (file < 0)
		{
			ft_useless(argv, i);
			if (errno == 21)
				ft_putstr(": Is a directory\n");
			else
				ft_putstr(": No such file or directory\n");
		}
		else
			while (read(file, &c, 1) > 0)
				ft_putchar(c);
		close(file);
	}
	return (0);
}
