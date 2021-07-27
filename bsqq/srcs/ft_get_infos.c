/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobrionn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:30:33 by jobrionn          #+#    #+#             */
/*   Updated: 2021/07/27 11:09:44 by jobrionn         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

t_bsq	ft_get_infos(char *str, char *str2)
{
	int		i;
	int		j;
	int		res;
	t_bsq	bizou;

	res = 0;
	j = 0;
	i = 0;
	i = ft_strlen(str);
	bizou.fill = str[--i];
	bizou.wall = str[--i];
	bizou.empty = str[--i];
	while ((str[j] >= '0' && str[j] <= '9') && (j < i))
		res = res * 10 + str[j++] - 48;
	bizou.height = res;
	bizou.len = ft_strlen(str2);
	return (bizou);
}

/*
char	*ft_read_standar_entry(void)
{
}
*/
