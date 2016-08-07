#ifndef MYLIB_H
# define MYLIB_H

# include <stdlib.h>

char	*ft_ftoa(float fl, int afterpoint);
char	*ft_itoa(int n);
int		ft_printf(char const * restrict format, ...);
int		ft_putfloat(float fl);
int		ft_putnbr(int n);
int		ft_putstr(char const *str);
size_t	ft_strlen(char const *s);

#endif
