/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobrionn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:27:26 by jobrionn          #+#    #+#             */
/*   Updated: 2021/07/28 11:16:12 by jufabreg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

int	ft_algo(int	**tab, int line, int index)
{
	int	min;

	min = 300000;
	if (tab[line][index] != 0)
	{
		if (tab[line - 1][index] < min)
			min = tab[line - 1][index];
		if (tab[line - 1][index - 1] < min)
			min = tab[line - 1][index - 1];
		if (tab[line][index - 1] < min)
			min = tab[line][index - 1];
	}
	else
		min = 0;
	return (min);
}

int	ft_get_bsq(int **tab, t_bsq infos)
{
	int	i;
	int	j;
	int	max;

	max = 0;
	i = 0;
	while (++i < infos.height + 1)
	{
		j = 0;
		while (++j < infos.len + 1)
			if (tab[i][j] > max)
				max = tab[i][j];
	}
	return (max);
}

t_coord	ft_get_bsq_coord(int **tab, t_bsq infos)
{
	int		i;
	int		j;
	int		max;
	t_coord	coord;

	coord.x = 0;
	coord.y = 0;
	i = -1;
	max = ft_get_bsq(tab, infos);
	while (++i < infos.height + 1)
	{
		j = -1;
		while (++j < infos.len + 1)
		{
			if (tab[i][j] == max)
			{
				coord.x = j;
				coord.y = i;
				return (coord);
			}
		}
	}
	return (coord);
}

char	**ft_fill_bsq(char **res, int max, t_coord coord, t_bsq infos)
{
	int	x;
	int	y;
	int	max1;
	int	max2;

	max1 = max;
	y = coord.y + 1;
	while (max1-- > 0)
	{
		y--;
		max2 = max;
		x = coord.x - 1;
		while (max2-- > 0)
			res[y][x--] = infos.fill;
	}
	return (res);
}
