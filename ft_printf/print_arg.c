#include "ft_printf.h"

static void	flags()
{
	if (arg->left_justify && (arg->type == ''))
	if (arg->positive && (arg->type == ''))
	if (arg->space && (arg->type == ''))
	if (arg->hastag && (arg->type == ''))
	if (arg->zero && (arg->type == ''))
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
	int			n;

	i = arg->len > arg->width ? arg->len : arg->width;
	print = (wchar_t *)malloc(sizeof(wchar_t) * (i + 1);
	print[i] = '\0';

	n = arg->width - arg->len;
	while (n > 0)
		if (arg->type)
	*/
	return (print_wchar_t(arg->specifier));
}
