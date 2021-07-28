/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobrionn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:30:24 by jobrionn          #+#    #+#             */
/*   Updated: 2021/07/27 10:30:28 by jobrionn         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

void	ft_free_char(char **res)
{
	int	i;

	i = -1;
	while (res[++i])
		free (res[i]);
	free (res);
}

void	ft_free_int(int **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free (tab[i]);
	free (tab);
}
