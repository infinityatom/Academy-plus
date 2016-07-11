#include "ft_printf.h"

int		extract_width(char *ptr, t_arg *arg)
{
	int		width;
	int		i;

	i = 0;
	width = 0;
	while (ptr[i] <= '9' && ptr[i] >= '0')
	{
		width *= 10;
		width += ptr[i] - '0';
		i++;
	}
	arg->width = width;
	return (i);
}
