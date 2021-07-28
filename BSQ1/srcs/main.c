/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobrionn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:31:59 by jobrionn          #+#    #+#             */
/*   Updated: 2021/07/27 20:17:33 by jufabreg         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

void	ft_error(void)
{
	write(2, "map error\n", 10);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
	{
		if (ft_bsq(argv[0], i, argc) == 0)
			ft_error();
	}
	else
	{
		while (++i < argc)
		{
			if (ft_bsq(argv[i], i, argc) == 0)
				ft_error();
		}
	}
}
