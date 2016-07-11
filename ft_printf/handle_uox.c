#include "ft_printf.h"

int		handle_uint(t_arg *arg, unsigned int n, int base, wchar_t a)
{
	size_t			size_ret;
	wchar_t			sign;
	unsigned int	temp_n;

	sign = (n < 0) ? -1 : 1;
	size_ret = 2 + (n < 0);
	temp_n = n;
	while ((n = n / base))
		size_ret++;
	n = temp_n;
	if (!(arg->specifier = (wchar_t *)malloc(sizeof(wchar_t) * size_ret--)))
		return (NULL);
	arg->specifier[size_ret--] = '\0';
	arg->specifier[size_ret--] = sign * (n%base<10?n%base+'0':n%base-10+a);
	while ((n = n / base))
		arg->specifier[size_ret--] = sign * (n%base<10?n%base+'0':n%base-10+a);
	if (sign < 0)
		arg->specifier[size_ret] = '-';
	return (ft_strlen(arg->specifier));
}

int		handle_ulint(t_arg *arg, unsigned long int n, int base, wchar_t a)
{
	size_t				size_ret;
	wchar_t				sign;
	unsigned long int	temp_n;

	sign = (n < 0) ? -1 : 1;
	size_ret = 2 + (n < 0);
	temp_n = n;
	while ((n = n / base))
		size_ret++;
	n = temp_n;
	if (!(arg->specifier = (wchar_t *)malloc(sizeof(wchar_t) * size_ret--)))
		return (NULL);
	arg->specifier[size_ret--] = '\0';
	arg->specifier[size_ret--] = sign * (n%base<10?n%base+'0':n%base-10+a);
	while ((n = n / base))
		arg->specifier[size_ret--] = sign * (n%base<10?n%base+'0':n%base-10+a);
	if (sign < 0)
		arg->specifier[size_ret] = '-';
	return (ft_strlen(arg->specifier));
}

int		handle_ullint(t_arg *arg, unsigned long long int n, int base, wchar_t a)
{
	size_t					size_ret;
	wchar_t					sign;
	unsigned long long int	temp_n;

	sign = (n < 0) ? -1 : 1;
	size_ret = 2 + (n < 0);
	temp_n = n;
	while ((n = n / base))
		size_ret++;
	n = temp_n;
	if (!(arg->specifier = (wchar_t *)malloc(sizeof(wchar_t) * size_ret--)))
		return (NULL);
	arg->specifier[size_ret--] = '\0';
	arg->specifier[size_ret--] = sign * (n%base<10?n%base+'0':n%base-10+a);
	while ((n = n / base))
		arg->specifier[size_ret--] = sign * (n%base<10?n%base+'0':n%base-10+a);
	if (sign < 0)
		arg->specifier[size_ret] = '-';
	return (ft_strlen(arg->specifier));
}

int		handle_uintmax_t(t_arg *arg, uintmax_t n, int base, wchar_t a)
{
	size_t		size_ret;
	wchar_t		sign;
	uintmax_t	temp_n;

	sign = (n < 0) ? -1 : 1;
	size_ret = 2 + (n < 0);
	temp_n = n;
	while ((n = n / base))
		size_ret++;
	n = temp_n;
	if (!(arg->specifier = (wchar_t *)malloc(sizeof(wchar_t) * size_ret--)))
		return (NULL);
	arg->specifier[size_ret--] = '\0';
	arg->specifier[size_ret--] = sign * (n%base<10?n%base+'0':n%base-10+a);
	while ((n = n / base))
		arg->specifier[size_ret--] = sign * (n%base<10?n%base+'0':n%base-10+a);
	if (sign < 0)
		arg->specifier[size_ret] = '-';
	return (ft_strlen(arg->specifier));
}
