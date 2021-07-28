/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobrionn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:31:59 by jobrionn          #+#    #+#             */
/*   Updated: 2021/07/28 11:17:51 by jufabreg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

void	ft_error(int i, int argc)
{
	write(2, "map error\n", 10);
	if (i < argc - 1)
		ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
	{
		if (ft_bsq(argv[0], i, argc) == 0)
			ft_error(i, argc);
	}
	else
	{
		while (++i < argc)
		{
			if (ft_bsq(argv[i], i, argc) == 0)
				ft_error(i, argc);
		}
	}
}
