#ifndef MYLIB_H
# define MYLIB_H

# include <stdlib.h>

char	*ft_ftoa(float fl, int afterpoint);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int		ft_printf(char const * restrict format, ...);
int		ft_putfloat(float fl);
int		ft_putnbr(int n);
int		ft_putstr(char const *str);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(char const *s);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char	*ft_strnew(size_t size);
int		get_next_line(int fd, char **line, size_t buff_size);

#endif
