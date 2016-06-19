#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

char	*ft_ftoa(float fl, int afterpoint);
char	*ft_itoa(int n);
void	*ft_memcpy(void *dst, void const *src, size_t n);
int		ft_printf(char const * restrict format, ...);
int		ft_putfloat(float fl);
int		ft_putnbr(int n);
int		ft_putstr(char const *str);
void	*ft_realloc(void *ptr, size_t size_o, size_t size_n);
size_t	ft_strlen(char const *s);

#endif
