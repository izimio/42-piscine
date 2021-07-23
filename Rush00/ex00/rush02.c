/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcollon <justincollon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 09:59:40 by jcollon           #+#    #+#             */
/*   Updated: 2021/07/10 10:44:42 by jcollon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(int cx, int cy, int x, int y)
{
	if (cx == 1 && cy == 1)
		ft_putchar('A');
	else if (cx == x && cy == 1)
		ft_putchar('A');
	else if (cx == 1 && cy == y)
		ft_putchar('C');
	else if (cx == x && cy == y)
		ft_putchar('C');
	else if (((cx > 1 && cx < x) && cy == 1)
		 || ((cx > 1 || cx < x) && cy == y))
		ft_putchar('B');
	else if (cx == 1 || cx == x)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

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
			print_line(cx, cy, x, y);
			cx++;
		}
		cx = 1;
		if (x > 0 && y > 0)
			ft_putchar('\n');
	}
}
