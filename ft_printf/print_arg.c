#include "ft_printf.h"
#include <unistd.h>

wchar_t		*mallocwchar(size_t n, wchar_t c)
{
	wchar_t		*ptr;
	size_t		i;

	ptr = (wchar_t *)malloc(sizeof(wchar_t) * (n + 1));
	i = 0;
	while (i < n)
		ptr[i++] = c;
	ptr[i] = '\0';
	return (ptr);
}

static void		process_precision(t_arg *arg)
{
	if (arg->precision == NULL)
		return ;
	if (arg->type == 'i' || arg->type == 'd' || arg->type == 'D' ||
		arg->type == 'u' || arg->type == 'o' || arg->type == 'O' ||
		arg->type == 'x' || arg->type == 'X')
	{
		if (*arg->precision > arg->len)
		{
			arg->specifier = ft_realloc(arg->specifier, arg->len, *arg->precision, '0');
			arg->len = *arg->precision;
		}
		else if (*arg->precision == 0 && arg->len == 1 && *arg->specifier == '0')
			*arg->specifier = '\0';
	}
	if (*arg->precision < arg->len)
		if (arg->type == 's' || arg->type == 'S')
		{
			arg->specifier = ft_realloc(arg->specifier, *arg->precision, *arg->precision, '\0');
			arg->len = *arg->precision;
		}
}

static int	print_wchar_t(wchar_t *str)
{
	int		i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], sizeof(wchar_t));
		i++;
	}
	return (i);
}

static void		process_left_justify(wchar_t *print, t_arg *arg, size_t len)
{
	size_t	n;
	size_t	i;

	n = 0;
	if (arg->left_justify == false)
	{
		i = len - arg->len;
		if (arg->zero == true)
			if (arg->type == 'i' || arg->type == 'd' || arg->type == 'D' ||
				arg->type == 'u' || arg->type == 'o' || arg->type == 'O' ||
				arg->type == 'x' || arg->type == 'X')
				while (i > n)
					print[n++] = '0';
		print += i;
	}
	n = 0;
	while(arg->len > n)
	{
		print[n] = arg->specifier[n];
		n++;
	}
}

static void		process_sign(t_arg *arg, size_t i)
{
	if (!(arg->type == 'i' || arg->type == 'd' || arg->type == 'D' ||
		arg->type == 'u' || arg->type == 'o' || arg->type == 'O' ||
		arg->type == 'x' || arg->type == 'X'))
		return ;
	if (arg->neg == true)
	{
		arg->specifier = ft_realloc(arg->specifier, arg->len, i, '0');
		*arg->specifier = '-';
		arg->len += i - arg->len;
	}
	else if (arg->positive == true)
	{
		arg->specifier = ft_realloc(arg->specifier, arg->len, i, '0');
		*arg->specifier = '+';
		arg->len += i - arg->len;
	}
	else if (arg->space == true)
	{
		arg->specifier = ft_realloc(arg->specifier, arg->len, i, '0');
		*arg->specifier = ' ';
		arg->len += i - arg->len;
	}
}

static void		process_hastag(t_arg *arg, size_t i)
{
	if (arg->hastag == false || (arg->len == 1 && *arg->specifier == '0'))
		return ;
	if (arg->type == 'o')
	{
		arg->specifier = ft_realloc(arg->specifier, arg->len, i, '0');
		arg->len += i - arg->len;
	}
	else if (arg->type == 'x')
	{
		arg->specifier = ft_realloc(arg->specifier, arg->len, i + 1, '0');
		arg->specifier[1] = 'x';
		arg->len += i - arg->len + 1;
	}
	else if (arg->type == 'X')
	{
		arg->specifier = ft_realloc(arg->specifier, arg->len, i + 1, '0');
		arg->specifier[1] = 'X';
		arg->len += i - arg->len + 1;
	}
}

int		print_arg(t_arg *arg)
{
	wchar_t		*print;
	size_t		i;

	process_precision(arg);
	i = arg->len + 1;
	if (arg->left_justify == false && arg->zero == true)
	{
		if (arg->type == 'i' || arg->type == 'd' || arg->type == 'D' ||
			arg->type == 'u' || arg->type == 'o' || arg->type == 'O' ||
			arg->type == 'x' || arg->type == 'X')
			i = arg->len > arg->width ? arg->len : arg->width;
	}
	process_sign(arg, i);
	process_hastag(arg, i);
	i = arg->len > arg->width ? arg->len : arg->width;
	print = mallocwchar(i, ' ');
	process_left_justify(print, arg, i);
	return (print_wchar_t(print));
}
/*
int		print_arg(t_arg *arg)
{
	wchar_t		*print;
	wchar_t		i;

	i = arg->len > arg->width ? arg->len : arg->width;
	process_precision(arg);
	if (arg->left_justify == false && arg->zero == true)
	{
		if (arg->type == 'i' || arg->type == 'd' || arg->type == 'D' ||
			arg->type == 'u' || arg->type == 'o' || arg->type == 'O' ||
			arg->type == 'x' || arg->type == 'X')
		{
			print = mallocwchar(i, '0');
		}
	}
	else
	{
		print = mallocwchar(i, ' ');
	}

}
*/
