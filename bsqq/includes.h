/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobrionn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:50:20 by jobrionn          #+#    #+#             */
/*   Updated: 2021/07/27 16:22:24 by jobrionn         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
typedef struct s_bsq
{
	char	wall;
	char	empty;
	char	fill;
	int		len;
	int		height;
}				t_bsq;
typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;
int		ft_strlen(char *str);
void	ft_putstr(char *s);
void	ft_putchar(char c);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
char	**ft_split(char *s, char c);
char	*ft_get_map_in_str(char *str);
t_bsq	ft_get_infos(char *str, char *str2);
int		**ft_create_double_int(char **res, t_bsq infos);
char	**ft_get_map_in_double(char *str);
int		ft_bsq(char *str, int i, int argc);
int		**ft_use_algo(int **tab, t_bsq	infos);
t_coord	ft_get_bsq_coord(int **tab, t_bsq infos);
int		ft_get_bsq(int **tab, t_bsq infos);
char	**ft_fill_bsq(char **res, int max, t_coord coord, t_bsq infos);
void	ft_final_print_and_free(char **res, int i, int argc);
void	ft_error(void);
int		ft_check_map(char **res, t_bsq infosi, char *s);
int		ft_check_file(char *str);
int		ft_algo(int	**tab, int line, int index);
#endif
