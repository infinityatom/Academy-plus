#ifndef MYLIB_H
# define MYLIB_H

# include <stdlib.h>

typedef enum { false = 0, true = 1 } bool;

int		ft_atoi(char *str);
char	*ft_ftoa(float fl, int afterpoint);
char	*ft_itoa(int n);
int		ft_printf(char const * restrict format, ...);
int		ft_putfloat(float fl);
int		ft_putnbr(int n);
int		ft_putstr(char const *str);
size_t	ft_strlen(char const *s);
int		get_next_line(int const fd, char **line);

#endif
