#include "includes.h"

int	ft_calc_buff_size(char *str)
{
	int		fd;
	int		i;
	char	buf[1024];

	buf[1023] = '\0';
	i = 0;
	fd = open(str, O_RDONLY);
	while (read(fd, &buf, 1024) > 0)
		i += ft_strlen(buf);
	close(fd);
	return (i);
}

char	*ft_create_tab_of_dict(char *str)
{
	int		fd;
	char	*buf;
	int		len;
	char	c;
	int		i;

	i = -1;
	len = ft_calc_buff_size(str);
	fd = open(str, O_RDONLY);
	buf = malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (NULL);
	while (read(fd, &c, 1) > 0)
		buf[++i] = c;
	buf[len] = '\0';
	close(fd);
	return (buf);
}

t_elem	*ft_create_elem_tab(char **res)
{
	int		i;
	int		j;
	t_elem	*tab;

	j = 0;
	i = -1;
	tab = malloc(sizeof(t_elem) * (ft_count_correct_lines_in_dict(res) + 1));
	if (!tab)
		return (NULL);
	while (res[++i] != 0)
	{
		if (ft_check_dict_each_line(res[i]) == 1)
		{
			tab[j].power = 0;
			tab[j].key = 10;
			if (ft_atoi_for_key(ft_parse_dict_key(res[i])) < 100)
				tab[j].key = ft_atoi_for_key(ft_parse_dict_key(res[i]));
			else
				tab[j].power = ft_parse_dict_power(ft_parse_dict_key(res[i]));
			tab[j++].value = ft_parse_dict_value(res[i]);
		}
	}
	ft_free_char(res);
	tab[j].power = -1;
	return (tab);
}
