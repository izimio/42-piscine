/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobrionn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:27:32 by jobrionn          #+#    #+#             */
/*   Updated: 2021/07/27 16:13:01 by jobrionn         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

char	*ft_scanff(void)
{
	int		count;
	char	mini_buff;
	char	buff[5000];
	char	*str;

	count = 0;
	while (read(0, &mini_buff, 1))
		buff[count++] = mini_buff;
	buff[count] = 0;
	str = malloc((count) * sizeof(char));
	count = -1;
	while (buff[++count])
		str[count] = buff[count];
	str[count] = 0;
	return (str);
}

int	ft_bsq(char *str, int i, int argc)
{
	char	**res;
	int		**tab;
	char	*s;
	t_bsq	infos;

	if (ft_check_file(str) == 0 && argc > 1)
		return (0);
	if (argc == 1)
		s = ft_scanff();
	else
		s = ft_get_map_in_str(str);
	res = ft_get_map_in_double(s);
	if (!res[1] || !res[0])
		return (0);
	infos = ft_get_infos(res[0], res[1]);
	if (ft_check_map(res, infos, s) == 0)
		return (0);
	tab = ft_create_double_int(res, infos);
	res = ft_fill_bsq(res, ft_get_bsq(tab, infos),
			ft_get_bsq_coord(tab, infos), infos);
	ft_final_print_and_free(res, i, argc);
	return (1);
}
