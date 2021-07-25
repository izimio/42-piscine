#include "includes.h"

char	**ft_get_all_keys(char *str)
{
	int		i;
	char	*s;
	char	**res;
	char	**content;
	int		len;

	i = -1;
	s = ft_create_tab_of_dict(str);
	res = ft_split(s, '\n');
	len = ft_count_correct_lines_in_dict(res);
	content = malloc(sizeof(char *) * (len + 1));
	if (!content)
		return (NULL);
	while (++i < len)
		content[i] = ft_parse_dict_key(res[i]);
	content[len] = 0;
	return (content);
}

int	ft_check_primary_key(char **prim_key, char **ac_key)
{
	int	i;
	int	j;
	int	trigger;

	trigger = 0;
	i = -1;
	while (prim_key[++i] != 0)
	{
		j = -1;
		while (ac_key[++j] != 0)
			if (ft_strcmp(prim_key[i], ac_key[j]) == 0)
				trigger = 1;
		if (trigger == 0)
			return (0);
		trigger = 0;
	}
	ft_free_char(prim_key);
	ft_free_char(ac_key);
	return (1);
}

int	ft_check_basic_entry(char *s1, char *s2)
{
	char	**d1;
	char	**d2;

	d1 = ft_get_all_keys(s1);
	d2 = ft_get_all_keys(s2);
	if (!d1 || !d2)
		return (0);
	return (ft_check_primary_key(d1, d2));
}
