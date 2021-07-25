#include "includes.h"
char	*free_all(char **res, int j)
{
	int		i;

	i = 0;
	while (i != j)
		free(res[i++]);
	free(res);
	return (NULL);
}

char	*malloc_a_case(const char *str, char c, char **res, int index)
{
	int		i;
	char	*buf;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	buf = malloc(sizeof(char) * (i + 1));
	if (!buf)
		return (free_all(res, index));
	i = 0;
	while (str[i] != c && str[i])
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

int	malloc_all(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

char	**ft_split(char *s, char c)
{
	char		**res;
	int			i;

	i = 0;
	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (malloc_all(s, c) + 1));
	if (!res)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
		{
			res[i] = malloc_a_case(s, c, res, i);
			if (!res[i])
				return (NULL);
			while (*s != c && *s)
				s++;
			i++;
		}
	}
	res[i] = 0;
	return (res);
}
