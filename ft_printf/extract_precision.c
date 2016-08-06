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
	if (*ptr <= '9' && *ptr >= '0')
	{
		arg->precision = (size_t *)malloc(sizeof(size_t));
		while (ptr[i] <= '9' && ptr[i] >= '0')
		{
			precision *= 10;
			precision += ptr[i] - '0';
			i++;
		}
		*arg->precision = precision;
	}
	return (i + 1);
}
