#include "ft_printf.h"

int		extract_precision(char *ptr, t_arg *arg)
{
	size_t	precision;
	int		i;

	if (*ptr != '.')
		return (0);
	i = 0;
	precision = 0;
	ptr += 1;
	while (ptr[i] <= '9' && ptr[i] >= '0')
	{
		precision *= 10;
		precision += ptr[i] - '0';
		i++;
	}
	arg->precision = precision;
	return (i);
}
