#ifndef FT_INCLUDES_H
# define FT_INCLUDES_H
# include <stdlib.h>
# include <unistd.h>
char	**ft_split(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_strlen(char *s);
void	ft_free_tab(int	**tab, char **views);
int		**ft_tab_init(void);
void	ft_print_tab(int **tab);
int		ft_check_error(char *str);
int		ft_is_solvable(int	**tab);
int		ft_possibility(int **tab, int nb, int col, int row);
int		ft_count_possibility(int **tab, int col, int row);
int		*ft_tab_list_possibility(int **tab, int col, int row);
int		ft_check_views(int **tab, int row, int col, char **views);
void	ft_backtracking(int **tab, char **views,
			int *tab_possibility);
int		**ft_solve(char *str);
#endif
