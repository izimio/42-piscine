#ifndef INCLUDES_H
# define INCLUDES_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
void	ft_putchar(char c);
void	ft_putstr(char *s);
int		**ft_atoi(char *str);
int		ft_atoi_for_key(char *str);
int		ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);
int		ft_count_dict_lines(char *str);
char	*ft_create_tab_of_dict(char *str);
int		ft_count_dict_lines(char *str);
int		ft_count_correct_lines_in_dict(char **res);
char	**ft_split(char *s, char c);
char	*ft_parse_dict_value(char *str);
char	*ft_parse_dict_key(char *str);
int		ft_parse_dict_power(char *str);
int		ft_check_dict_each_line(char *str);
int		ft_check_agument(char *str);
int		ft_check_all_dict(char *str, char **res);
void	ft_free_char(char **res);
void	ft_free_int(int **tab, int size);
int		ft_check_basic_entry(char *s1, char *s2);
typedef struct s_elem
{
	int		key;
	int		power;
	char	*value;
}				t_elem;
t_elem	*ft_create_elem_tab(char **res);
int		ft_is_printable(int **tab);
void	ft_free_t_elem(t_elem	*tab);
void	ft_print_final(int **nb_tab, t_elem *dict);
#endif
