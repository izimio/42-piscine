#include "ft_tail.h"

void	ft_useless(char **argv, int i, int choice)
{
	if (choice == 1)
	{
		ft_putstr(basename(argv[0]));
		ft_putstr(": ");
		ft_putstr(argv[i]);
		ft_putstr(": No such file or directory\n");
	}
	else if (choice == 2)
	{
		ft_putstr(basename(argv[0]));
		ft_putstr(": ");
		ft_putstr("illegal option -- \n");
		ft_putstr(argv[1]);
		ft_putstr("usage: tail [-F | -f | -r] [-q] [-b # | -c #| -n #] [file ...]\n");
	}
}

void	ft_useless_tail(char *str)
{
	ft_putstr("==> ");
	ft_putstr(str);
	ft_putstr(" <==\n");
}

void	ft_tail_without_parameter(int argc, char **argv)
{
	int		file;
	int		i;

	i = 0;
	while (++i < argc)
	{
		file = open(argv[i], O_RDWR);
		if (file < 0)
		{
			ft_useless(argv, i, 1);
			return ;
		}
		if (argc > 2)
			ft_useless_tail(argv[i]);
		ft_print_last_ten_lines(argv[i]);
		if (argc >= 2 && i != argc - 1)
			ft_putchar('\n');
		close(file);
	}
}

void	ft_tail_with_c_parameter(int argc, char **argv)
{
	int		file;
	int		i;

	i = 2;
	if (!argv[3])
	{
		ft_useless(argv, i, 2);
		return ;
	}
	while (++i < argc)
	{
		file = open(argv[i], O_RDWR);
		if (file < 0)
		{
			ft_useless(argv, i, 1);
			return ;
		}
		if (argc > 3)
			ft_useless_tail(argv[i]);
		ft_print_bytes(ft_atoi(argv[2]), argv[i]);
		if (argc >= 5 && i != argc - 1)
			ft_putchar('\n');
		close(file);
	}
}

int	main(int argc, char **argv)
{
	char	c;
	int		i;

	i = 0;
	if (argc == 1)
		while (read(0, &c, 1) > 0)
			;
	else if (argc >= 3 && ft_strcmp(argv[1], "-c") == 0)
	{
		ft_tail_with_c_parameter(argc, argv);
		return (0);
	}
	else if (argc >= 3 && ft_strcmp(&argv[1][0], "-") == 0
		&& ft_strcmp(&argv[1][1], "c") != 0)
	{
		ft_useless(argv, i, 2);
		return (0);
	}
	else if (argc >= 1 && ft_strcmp(&argv[1][0], "-") != 0)
		ft_tail_without_parameter(argc, argv);
	return (0);
}
