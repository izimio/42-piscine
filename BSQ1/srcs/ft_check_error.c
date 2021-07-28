/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jufabreg <jufabreg@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:27:50 by jobrionn          #+#    #+#             */
/*   Updated: 2021/07/28 08:39:57 by jufabreg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

int	ft_check_first_line(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	i = ft_strlen(str);
	if (i < 4)
		return (0);
	if (str[i] == str[i - 1] || str[i] == str[i - 2])
		return (0);
	i--;
	if (str[i] == str[i + 1] || str[i] == str[i - 1])
		return (0);
	i--;
	if (str[i] == str[i + 1] || str[i] == str[i + 2])
		return (0);
	return (1);
}

int	ft_check_line(char **res, t_bsq infos)
{
	int	i;
	int	len;
	int	j;

	len = ft_strlen(res[1]);
	if (infos.height == 0 && len == 0)
		return (0);
	i = 0;
	while (res[++i])
	{
		j = -1;
		if (ft_strlen(res[i]) != len || len < 1)
			return (0);
		while (res[i][++j])
			if (res[i][j] != infos.wall && res[i][j] != infos.empty)
				return (0);
	}
	return (i == infos.height + 1);
}

int	ft_check_newlines(char *str, t_bsq infos)
{
	int	i;
	int	len;

	i = 0;
	while (str[i] != '\n')
		i++;
	len = i + (infos.height * (infos.len + 1));
	while (i < len)
	{
		i += infos.len + 1;
		if (str[i] != '\n' && i < len + 1)
			return (0);
	}
	return (1);
}

int	ft_check_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd <= 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	ft_check_map(char **res, t_bsq infos, char *s)
{
	if (ft_check_newlines(s, infos) == 0 || ft_check_line(res, infos) == 0
		|| ft_check_first_line(res[0]) == 0)
		return (0);
	return (1);
}
