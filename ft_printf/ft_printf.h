#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>

typedef enum { false = 0, true = 1 } bool;

typedef struct	s_arg
{
	bool		left_justify;
	bool		positive;
	bool		space;
	bool		hastag;
	bool		zero;
	size_t		width;
	size_t		precision;
	wchar_t		*specifier;
	size_t		len;
	char		type;
	bool		neg;
	enum {
		null,
		hh,
		h,
		l,
		ll,
		j,
		z
	}	length;
}				t_arg;

int		extract_flags(char *ptr, t_arg *arg);
int		extract_length(char *ptr, t_arg *arg);
int		extract_precision(char *ptr, t_arg *arg);
int		extract_specifier(char *ptr, t_arg *arg, va_list *ap);
int		extract_width(char *ptr, t_arg *arg);

char	*ft_ftoa(float fl, int afterpoint);
char	*ft_itoa(int n);
void	ft_memcpy(wchar_t *dst, wchar_t *src, size_t n);
int		ft_printf(char const * restrict format, ...);
int		ft_putchar(char const c);
int		ft_putfloat(float fl);
int		ft_putnbr(int n);
int		ft_putstr(char const *str);
int		ft_putwchar(wchar_t const c);
wchar_t	*ft_realloc(wchar_t *ptr, size_t size_copy, size_t size_new, wchar_t c);
size_t	ft_strlen(wchar_t *s);

int		handle_int(t_arg *arg, int n);
int		handle_lint(t_arg *arg, long int n);
int		handle_llint(t_arg *arg, long long int n);
int		handle_intmax_t(t_arg *arg, intmax_t n);
int		handle_size_t(t_arg *arg, size_t n, int base, wchar_t a);

int		handle_wint_t(t_arg *arg, wint_t n);
int		handle_char(t_arg *arg, int n);
int		handle_wchar_t(t_arg *arg, wchar_t *n);
int		handle_str(t_arg *arg, char *n);
int		handle_pointer(t_arg *arg, void *n);
int		handle_uint(t_arg *arg, unsigned int n, int base, wchar_t a);
int		handle_ulint(t_arg *arg, unsigned long int n, int base, wchar_t a);
int		handle_ullint(t_arg *arg, unsigned long long int n, int base, wchar_t a);
int		handle_uintmax_t(t_arg *arg, uintmax_t n, int base, wchar_t a);

int		print_arg(t_arg *arg);

#endif
