#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>

typedef enum { false, true } bool;

typedef struct	s_arg
{
	bool		left_justify;
	bool		positive;
	bool		space;
	bool		hastag;
	bool		zero;
	size_t		width;
	size_t		precision;
	enum {
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}			length;
}				t_arg;

char	*ft_ftoa(float fl, int afterpoint);
char	*ft_itoa(int n);
void	*ft_memcpy(void *dst, void const *src, size_t n);
int		ft_printf(char const * restrict format, ...);
int		ft_putchar(char const c);
int		ft_putfloat(float fl);
int		ft_putnbr(int n);
int		ft_putstr(char const *str);
int		ft_putwchar(wchar_t const c);
void	*ft_realloc(void *ptr, size_t size_o, size_t size_n);
size_t	ft_strlen(char const *s);

#endif
