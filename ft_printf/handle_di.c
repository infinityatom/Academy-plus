#include "ft_printf.h"

int		handle_int(t_arg *arg, int n)
{
	size_t	size_ret;
	wchar_t	sign;
	int		temp_n;

	sign = (n < 0) ? -1 : 1;
	size_ret = 2 + (n < 0);
	temp_n = n;
	while ((n = n / 10))
		size_ret++;
	n = temp_n;
	if (!(arg->specifier = (wchar_t *)malloc(sizeof(wchar_t) * size_ret--)))
		return (NULL);
	arg->specifier[size_ret--] = '\0';
	arg->specifier[size_ret--] = sign * (n % 10) + '0';
	while ((n = n / 10))
		arg->specifier[size_ret--] = sign * (n % 10) + '0';
	if (sign < 0)
		arg->specifier[size_ret] = '-';
	return (ft_strlen(arg->specifier));
}

int		handle_lint(t_arg *arg, long int n)
{
	size_t		size_ret;
	wchar_t		sign;
	long int	temp_n;

	sign = (n < 0) ? -1 : 1;
	size_ret = 2 + (n < 0);
	temp_n = n;
	while ((n = n / 10))
		size_ret++;
	n = temp_n;
	if (!(arg->specifier = (wchar_t *)malloc(sizeof(wchar_t) * size_ret--)))
		return (NULL);
	arg->specifier[size_ret--] = '\0';
	arg->specifier[size_ret--] = sign * (n % 10) + '0';
	while ((n = n / 10))
		arg->specifier[size_ret--] = sign * (n % 10) + '0';
	if (sign < 0)
		arg->specifier[size_ret] = '-';
	return (ft_strlen(arg->specifier));
}

int		handle_llint(t_arg *arg, long long int n)
{
	size_t			size_ret;
	wchar_t			sign;
	long long int	temp_n;

	sign = (n < 0) ? -1 : 1;
	size_ret = 2 + (n < 0);
	temp_n = n;
	while ((n = n / 10))
		size_ret++;
	n = temp_n;
	if (!(arg->specifier = (wchar_t *)malloc(sizeof(wchar_t) * size_ret--)))
		return (NULL);
	arg->specifier[size_ret--] = '\0';
	arg->specifier[size_ret--] = sign * (n % 10) + '0';
	while ((n = n / 10))
		arg->specifier[size_ret--] = sign * (n % 10) + '0';
	if (sign < 0)
		arg->specifier[size_ret] = '-';
	return (ft_strlen(arg->specifier));
}

int		handle_intmax_t(t_arg *arg, intmax_t n)
{
	size_t		size_ret;
	wchar_t		sign;
	intmax_t	temp_n;

	sign = (n < 0) ? -1 : 1;
	size_ret = 2 + (n < 0);
	temp_n = n;
	while ((n = n / 10))
		size_ret++;
	n = temp_n;
	if (!(arg->specifier = (wchar_t *)malloc(sizeof(wchar_t) * size_ret--)))
		return (NULL);
	arg->specifier[size_ret--] = '\0';
	arg->specifier[size_ret--] = sign * (n % 10) + '0';
	while ((n = n / 10))
		arg->specifier[size_ret--] = sign * (n % 10) + '0';
	if (sign < 0)
		arg->specifier[size_ret] = '-';
	return (ft_strlen(arg->specifier));
}

int		handle_size_t(t_arg *arg, size_t n, int base, wchar_t a)
{
	size_t	size_ret;
	wchar_t	sign;
	size_t	temp_n;

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
