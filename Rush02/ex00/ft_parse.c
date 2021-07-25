#include "includes.h"

char	*ft_parse_dict_key(char *str)
{
	int		i;
	char	*toa;
	int		count;

	count = 0;
	i = -1;
	if (!str)
		return (NULL);
	while (str[++i] && str[i] != ':')
		count++;
	i = -1;
	toa = malloc(sizeof(char) * (count + 1));
	if (!toa)
		return (NULL);
	while (++i < count)
		toa[i] = str[i];
	toa[count] = '\0';
	return (toa);
}

int	ft_count_value_length(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != ':')
		i++;
	i++;
	while (str[i] == ' ')
		i++;
	while (str[i] >= 32 && str[i] < 127)
	{
		i++;
		count++;
	}
	return (count);
}	

char	*ft_parse_dict_value(char *str)
{
	int		i;
	char	*toa;
	int		j;
	int		len;

	len = ft_count_value_length(str);
	j = 0;
	i = 0;
	toa = malloc(sizeof(char) * len + 1);
	if (!toa)
		return (NULL);
	while (str[i] != ':')
		i++;
	i++;
	while (str[i] == ' ')
		i++;
	while (str[i] >= 32 && str[i] < 127)
		toa[j++] = str[i++];
	toa[len] = '\0';
	return (toa);
}

int	ft_parse_dict_power(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '0')
			count++;
	}
	return (count);
}
