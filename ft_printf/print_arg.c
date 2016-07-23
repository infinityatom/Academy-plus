#include "ft_printf.h"
#include <unistd.h>

/*
static void	flags()
{
	if (arg->left_justify && (arg->type == ''))
	if (arg->positive && (arg->type == ''))
	if (arg->space && (arg->type == ''))
	if (arg->hastag && (arg->type == ''))
	if (arg->zero && (arg->type == ''))
}
*/
/*
static void		process_left_justify(t_arg *arg, wchar_t *print, int len)
{
	int		n;

	n = 0;
	if (arg->left_justify == true)
		while(len > n)
		{
			print[n] = arg->specifier[n];
			n++;
		}
	else
	{
		n = len - 1;
		while(n >= 0)
		{
			print[n] = arg->specifier[n];
			n--;
		}
	}
}
*/
static void		process_precision(t_arg *arg)
{
	if (arg->type == 'p' || arg->type == 'c' || arg->type == 'C')
		return ;
	if (arg->precision > arg->len)
		if (arg->type == 'i' || arg->type == 'd' || arg->type == 'D' ||
			arg->type == 'u' || arg->type == 'o' || arg->type == 'O' ||
			arg->type == 'x' || arg->type == 'X')
		{
			arg->specifier = ft_realloc(arg->specifier, arg->len, arg->precision, '0');
			arg->len = arg->precision;
		}
	if (arg->precision < arg->len)
		if (arg->type == 's' || arg->type == 'S')
		{
			arg->specifier = ft_realloc(arg->specifier, arg->precision, arg->precision, '\0');
			arg->len = arg->precision;
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


int		print_arg(t_arg *arg)
{
/*
	wchar_t		*print;
	size_t		i;

	i = arg->len > arg->width ? arg->len : arg->width;
	print = (wchar_t *)malloc(sizeof(wchar_t) * (i + 1);
	print[i] = '\0';

	process_left_justify(arg, print, i);*/
	process_precision(arg);
	return (print_wchar_t(arg->specifier));
}
