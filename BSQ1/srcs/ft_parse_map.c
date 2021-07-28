/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobrionn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:30:44 by jobrionn          #+#    #+#             */
/*   Updated: 2021/07/27 21:48:10 by jufabreg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

int	ft_calc_buff_size(char *str)
{
	int		fd;
	int		i;
	char	buff[2048];
	int		sd;

	sd = 1;
	buff[2047] = '\0';
	i = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (sd > 0)
	{
		sd = read(fd, buff, 2048);
		if (sd < 0)
			return (0);
		i += sd;
	}
	close(fd);
	return (i);
}

char	*ft_get_map_in_str(char *str)
{
	int		fd;
	int		len;
	char	*res;
	int		s;

	len = ft_calc_buff_size(str);
	if (len == -1)
		return (0);
	res = malloc(sizeof(char) * (len + 1));
	fd = open(str, O_RDONLY);
	if (!res || !fd)
		exit(1);
	s = read(fd, res, len);
	res[len] = '\0';
	close(fd);
	return (res);
}

char	**ft_get_map_in_double(char *str)
{
	char	**res;

	res = ft_split(str, '\n');
	if (!res)
		exit(1);
	return (res);
}

int	**ft_malloc_int_tab(t_bsq infos)
{
	int	**tab;
	int	i;

	i = -1;
	tab = malloc(sizeof(int *) * infos.height + 1);
	if (!tab)
		exit(1);
	while (++i < infos.height + 1)
	{
		tab[i] = malloc(sizeof(int) * infos.len + 1);
		if (!tab[i])
			exit(1);
	}
	i = -1;
	while (++i < infos.len + 1)
		tab[0][i] = 0;
	return (tab);
}

int	**ft_create_double_int(char **res, t_bsq infos)
{
	int	i;
	int	j;
	int	**tab;

	i = 0;
	tab = ft_malloc_int_tab(infos);
	while (++i < (infos.height + 1))
	{
		j = 0;
		tab[i][0] = 0;
		while (++j < (infos.len + 1))
		{
			if (res[i][j - 1] == infos.empty)
				tab[i][j] = 1;
			if (res[i][j - 1] == infos.wall)
				tab[i][j] = 0;
			tab[i][j] += ft_algo(tab, i, j);
		}
	}
	return (tab);
}	
