#include "ft_includes.h"

void	ft_error(void)
{
	ft_putstr("Error\n");
}

int	main(int argc, char **argv)
{
	char	**res;
	int		*tab_possibility;
	int		**arr;

	tab_possibility = NULL;
	if (argc == 2)
		res = ft_split(argv[1]);
	arr = ft_tab_init();
	if (argc != 2 || ft_check_error(argv[1]) == 0)
		ft_error();
	else
	{
		ft_backtracking(arr, res, tab_possibility);
		if (ft_is_solvable(arr) == 0)
			ft_error();
		else
			ft_print_tab(arr);
		ft_free_tab(arr, res);
	}
	return (0);
}
