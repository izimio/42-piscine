#include "ft_list_sort.h"

int	incharset(char c)
{
	if (c == '\n' || c == '\t' || c == ' ')
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
		while (str[i] && incharset(str[i]))
			i++;
		if (str[i] && !incharset(str[i]))
		{
			count++;
			while (str[i] && !incharset(str[i]))
				i++;
		}
	}
	return (count);
}

char 	*wmalloc(char *str)
{
	char *toa;
	int i;

	i = 0;
	while (str[i] && !incharset(str[i]))
		i++;
	toa = malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i] && !incharset(str[i]))
	{
		toa[i] = str[i];
		i++;
	}
	toa[i] = '\0';
	return (toa);
}

char **ft_split(char *str)
{
	int	i;
	int	j;
	char **res;

	i = 0;
	j = 0;
	res = malloc(sizeof(char *) * wcount(str) + 1);
	while (str[i])
	{
		while (str[i] && incharset(str[i]))
			i++;
		if (str[i] && !incharset(str[i]))
		{
			res[j] = wmalloc(&str[i]);
			j++;
			while (str[i] && !incharset(str[i]))
				i++;
		}
	}
	res[j] = 0;
	return (res);
}

int main()
{
	char **res;
	int i = -1;
	res = ft_split("coucou les amis je mange du pain lol olo l nndnd ");
	while (res[++i])
		printf("%s\n",res[i]);
}
