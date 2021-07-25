#include "includes.h"
void	ft_error(int type)
{
	if (type == 0)
		ft_putstr("Error\n");
	if (type == 1)
		ft_putstr("Dict Error\n");
}

int	ft_check_main(int argc, char **argv)
{
	char	**res;

	res = NULL;
	if (argc == 2)
		res = ft_split(ft_create_tab_of_dict("numbers.dict"), '\n');
	if (argc == 3)
		res = ft_split(ft_create_tab_of_dict(argv[1]), '\n');
	if (!res)
		return (0);
	if (argc == 2 || argc == 3)
	{
		if ((argc == 2 && ft_check_all_dict("numbers.dict", res) == 0)
			|| (argc == 3 && ft_check_all_dict(argv[1], res) == 0))
		{
			ft_error(1);
			return (0);
		}
	}
	free (res);
	return (1);
}

int	ft_check_main_2(int argc, char **argv)
{
	if (argc <= 1 || argc >= 4)
		return (0);
	if (ft_check_agument(argv[argc - 1]) == 0)
	{
		ft_error(0);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_elem	*d;
	int		**nb_tab;

	nb_tab = NULL;
	d = NULL;
	if (ft_check_main(argc, argv) == 0 || ft_check_main_2(argc, argv) == 0)
		return (0);
	if (argc == 3)
	{
		d = ft_create_elem_tab(ft_split(ft_create_tab_of_dict(argv[1]), '\n'));
		nb_tab = ft_atoi(argv[2]);
	}
	else if (argc == 2)
	{
		d = ft_create_elem_tab(ft_split(
					ft_create_tab_of_dict("numbers.dict"), '\n'));
		nb_tab = ft_atoi(argv[1]);
	}
	if (!ft_is_printable(nb_tab))
		ft_error(1);
	else if (nb_tab && d)
		ft_print_final(nb_tab, d);
	ft_free_t_elem(d);
	return (0);
}
