#include <stdlib.h>

int	in_charset(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (charset[i] == c)
			return (1);
	return (0);
}

int	wcount(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && in_charset(str[i], charset))
			i++;
		if (str[i] && !in_charset(str[i], charset))
		{
			count++;
			while (str[i] && !in_charset(str[i], charset))
				i++;
		}
	}
	return (count);
}

char	*wmalloc(char *str, char *charset)
{
	int		i;
	char	*toa;

	i = 0;
	while (str[i] && !in_charset(str[i], charset))
		i++;
	toa = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i] && !in_charset(str[i], charset))
	{
		toa[i] = str[i];
		i++;
	}
	toa[i] = '\0';
	return (toa);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 0;
	res = (char **)malloc(sizeof(char *) * wcount(str, charset) + 1);
	while (str[i])
	{
		while (str[i] && in_charset(str[i], charset))
			i++;
		if (str[i] && !in_charset(str[i], charset))
		{
			res[j] = wmalloc(&str[i], charset);
			j++;
			while (str[i] && !in_charset(str[i], charset))
				i++;
		}
	}
	res[j] = 0;
	return (res);
}
