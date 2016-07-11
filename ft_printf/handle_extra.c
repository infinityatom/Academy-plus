#include "ft_printf.h"

int		handle_wint_t(t_arg *arg, wint_t n)
{
	arg->specifier = (wchar_t *)malloc(sizeof(wchar_t) * 2);
	arg->specifier[0] = (wchar_t)n;
	arg->specifier[1] = '\0';
	return (1);
}

int		handle_char(t_arg *arg, int n)
{
	arg->specifier = (wchar_t *)malloc(sizeof(wchar_t) * 2);
	arg->specifier[0] = (wchar_t)n;
	arg->specifier[1] = '\0';
	return (1);
}

int		handle_wchar_t(t_arg *arg, wchar_t *n)
{
	int		i;

	i = 0;
	while (n[i] != '\0')
		i++;
	arg->specifier = (wchar_t *)malloc(sizeof(wchar_t) * i + 1);
	arg->specifier[i] = '\0';
	i = 0;
	while (n[i] != '\0')
		arg->specifier[i] = n[i];
	return (i);
}

int		handle_str(t_arg *arg, char *n)
{
	int		i;

	i = 0;
	while (n[i] != '\0')
		i++;
	arg->specifier = (wchar_t *)malloc(sizeof(wchar_t) * i + 1);
	arg->specifier[i] = '\0';
	i = 0;
	while (n[i] != '\0')
		arg->specifier[i] = (wchar_t)n[i];
	return (i);
}

int		handle_pointer(t_arg *arg, void *nr)
{
	size_t	size_ret;
	size_t	temp_n;
	size_t	n;

	n = (size_t)nr;
	size_ret = 2;
	temp_n = n;
	while ((n = n / 16))
		size_ret++;
	size_ret += 2;
	n = temp_n;
	if (!(arg->specifier = (wchar_t *)malloc(sizeof(wchar_t) * (size_ret--))))
		return (0);
	arg->specifier[size_ret--] = '\0';
	arg->specifier[size_ret--] = n % 16 < 10 ? n%16+'0' : n%16-10+'a';
	while ((n = n / 16))
		arg->specifier[size_ret--] = n % 16 < 10 ? n%16+'0' : n%16-10+'a';
	arg->specifier[0] = '0';
	arg->specifier[1] = 'x';
	return (ft_strlen(arg->specifier));
}
