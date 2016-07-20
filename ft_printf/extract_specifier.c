#include "ft_printf.h"

static int	extract_specifier_di(t_arg *arg, va_list *ap)
{
	if (arg->length != null)
	{
		if (arg->length == hh || arg->length == h)
			return (handle_int(arg, va_arg(*ap, int)));
		else if (arg->length == l)
			return (handle_lint(arg, va_arg(*ap, long int)));
		else if (arg->length == ll)
			return (handle_llint(arg, va_arg(*ap, long long int)));
		else if (arg->length == j)
			return (handle_intmax_t(arg, va_arg(*ap, intmax_t)));
		else if (arg->length == z)
			return (handle_size_t(arg, va_arg(*ap, size_t), 10, 'a'));
	}
	return (handle_int(arg, va_arg(*ap, int)));
}

static int	extract_specifier_uox(t_arg *arg, va_list *ap, char *ptr)
{
	wchar_t	a;
	int		i;

	i = 10;
	a = 'a';
	if (*ptr == 'o' || *ptr == 'O')
		i = 8;
	if (*ptr == 'x' || *ptr == 'X')
	{
		i = 16;
		a = 'A';
	}
	if (arg->length == hh || arg->length == h)
		return (handle_uint(arg, va_arg(*ap, unsigned int), i, a));
	else if (arg->length == l)
		return (handle_ulint(arg, va_arg(*ap, unsigned long int), i, a));
	else if (arg->length == ll)
		return (handle_ullint(arg, va_arg(*ap, unsigned long long int), i, a));
	else if (arg->length == j)
		return (handle_uintmax_t(arg, va_arg(*ap, uintmax_t), i, a));
	else if (arg->length == z)
		return (handle_size_t(arg, va_arg(*ap, size_t), i, a));
	return (handle_uint(arg, va_arg(*ap, unsigned int), i, a));
}

int		extract_specifier(char *ptr, t_arg *arg, va_list *ap)
{
	arg->type = *ptr;
	if (*ptr == 'd' || *ptr == 'D' || *ptr == 'i')
		return (extract_specifier_di(arg, ap));
	if (*ptr == 'u' || *ptr == 'U' ||
		*ptr == 'o' || *ptr == 'O' ||
		*ptr == 'x' || *ptr == 'X')
		return (extract_specifier_uox(arg, ap, ptr));
	if (*ptr == 'c' || *ptr == 'C')
	{
		if (arg->length == l)
			return (handle_wint_t(arg, va_arg(*ap, wint_t)));
		else
			return (handle_char(arg, va_arg(*ap, int)));
	}
	if (*ptr == 's' || *ptr == 'S')
	{
		if (arg->length == l || *ptr == 'S')
			return (handle_wchar_t(arg, va_arg(*ap, wchar_t *)));
		else
			return (handle_str(arg, va_arg(*ap, char *)));
	}
	if (*ptr == 'p')
		return (handle_pointer(arg, va_arg(*ap, void *)));
	return (0);
}
