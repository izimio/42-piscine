#include "includes.h"

int	ft_check_extension(char *str)
{
	int	i;
	int	len;

	i = -1;
	if (!str)
		return (0);
	len = ft_strlen(str);
	if (len <= 5)
		return (0);
	len--;
	if (str[len] == 't' && str[len - 1] == 'c' && str[len - 2] == 'i'
		&& str[len - 3] == 'd' && str[len - 4] == '.')
		return (1);
	return (0);
}

int	ft_check_agument(char *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_dict_each_line(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ')
		i++;
	if (str[i] == ':')
		i++;
	else
		return (0);
	while (str[i] == ' ')
		i++;
	while (str[i] >= 32 && str[i] < 127)
		i++;
	return (i == len);
}

int	ft_check_dict(char **res)
{
	int	i;

	i = 0;
	while (res[i] != 0)
	{
		if (ft_check_dict_each_line(res[i]) == 0 && res[i])
			return (0);
		i++;
	}
	if (i < 41)
		return (0);
	return (1);
}

int	ft_check_all_dict(char *str, char **res)
{
	if (ft_check_dict(res) == 0 || ft_check_extension(str) == 0
		|| ft_check_basic_entry("numbers.dict", str) == 0)
		return (0);
	return (1);
}
