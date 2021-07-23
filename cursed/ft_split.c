#include <stdlib.h>

int	is_in_charset(char c)
{
	if(c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int 	wcount(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_in_charset(str[i]))
			i++;
		if (str[i] && !is_in_charset(str[i]))
		{
			count++;
			while (str[i] && !is_in_charset(str[i]))
				i++;
		}
	}
	return (count);
}

char	*wmalloc(char *str)
{
	int	i;
	char	*toa;

	i = 0;
	while (str[i] && !is_in_charset(str[i]))
		i++;
	toa = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i] && !is_in_charset(str[i]))
	{
		toa[i] = str[i];
		i++;
	}	
	toa[i] = '\0';
	return (toa);
}

char	**ft_split(char	*str)
{
	int	i;
	int	j;
	char	**res;

	i = 0;
	j = 0;
	res = (char **)malloc(sizeof(char *) * wcount(str) + 1);
	while (str[i])
	{
		while (str[i] && is_in_charset(str[i]))
			i++;
		if (str[i] && !is_in_charset(str[i]))
		{
			res[j] = wmalloc(&str[i]);
			j++;
			while (str[i] && !is_in_charset(str[i]))
				i++;
		}
	}
	res[j] = 0;
	return (res);
}




int main()
{
	char **res;
	res = ft_split("coucou les amis\nje mange du \tgoute");
	int i = -1;
	while (res[++i])
		printf("%s\n",res[i]);
}




