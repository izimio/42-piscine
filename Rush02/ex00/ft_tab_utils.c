#include "includes.h"

int	ft_count_dict_lines(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
		if (str[i] == '\n')
			count++;
	return (count);
}

int	ft_count_correct_lines_in_dict(char **res)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (res[++i])
		if (ft_check_dict_each_line(res[i]) == 1)
			count++;
	return (count);
}
