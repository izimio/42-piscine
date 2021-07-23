/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <justincollon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 21:39:59 by jcollon           #+#    #+#             */
/*   Updated: 2021/07/10 10:51:35 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	cx;
	int	cy;

	cx = 1;
	cy = 0;
	while (++cy <= y)
	{
		while (cx <= x)
		{
			if (((cx == 1 || cx == x) && cy == 1)
				 || ((cx == 1 || cx == x) && cy == y))
				ft_putchar('o');
			else if (((cx > 1 && cx < x) && cy == 1)
				 || ((cx > 1 || cx < x) && cy == y))
				ft_putchar('-');
			else if (cx == 1 || cx == x)
				ft_putchar('|');
			else
				ft_putchar(' ');
			cx++;
		}
		cx = 1;
		if (x > 0 && y > 0)
			ft_putchar('\n');
	}
}
