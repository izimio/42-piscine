/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobrionn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:31:40 by jobrionn          #+#    #+#             */
/*   Updated: 2021/07/27 16:22:00 by jobrionn         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		ft_putchar(s[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_final_print_and_free(char **res, int i, int argc)
{
	int	j;

	j = 0;
	while (res[++j])
	{
		ft_putstr(res[j]);
		ft_putchar('\n');
	}
	if (i < argc - 1)
		ft_putchar('\n');
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	j;
	unsigned int	i;

	j = 0;
	while (dest[j])
		j++;
	i = 0;
	while (src[i] && i < nb)
	{
		dest[j + i] = src[i];
		i++;
	}
	dest[j + i] = '\0';
	return (dest);
}
