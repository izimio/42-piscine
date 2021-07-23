#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count(char **strs, int size, int sepl)
{
	int	count;

	count = 0;
	while (size--)
		count += ft_strlen(strs[size]) + sepl;
	return (count);
}

char	*check(int size, char *str, int j)
{
	if (size != 0)
		str[j] = '\0';
	if (size == 0)
		str = malloc(sizeof(str) * 1);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	char	*tmp;
	int		c;
	int		i;
	int		j;

	j = 1;
	if (size > 0)
		j = count(strs, size, ft_strlen(sep)) - ft_strlen(sep);
	str = malloc(sizeof(*str) * j);
	i = -1;
	c = 0;
	while (++i < size)
	{
		tmp = strs[i];
		while (tmp++[0])
			str[c++] = tmp[-1];
		if (i != size - 1)
		{
			tmp = &sep[0];
			while (tmp++[0])
				str[c++] = tmp[-1];
		}
	}
	return (check(size, str, j));
}

int main()
{
	char *strs[3];
	char *str;
	strs[0] = "";
	strs[1] = "shalla je marche";
	strs[2] = "sinon c est chiant en vrai";
		str = ft_strjoin(0, strs, "||,/,/,/,/,/|| ");
	printf("%s\n",str);
	free(str);
}
