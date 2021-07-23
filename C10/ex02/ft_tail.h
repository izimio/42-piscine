#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>
# include <unistd.h>
void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_strcmp(char *s1, char *s2);
void	ft_print_bytes(int bytes, char *str);
void	ft_print_last_ten_lines(char	*str);
int		ft_atoi(char *str);
#endif
