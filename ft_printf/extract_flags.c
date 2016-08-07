#include "ft_printf.h"

static int	extra(char c, t_arg *arg)
{
	if (c == '-')
		arg->left_justify = true;
	else if (c == '+')
		arg->positive = true;
	else if (c == ' ')
		arg->space = true;
	else if (c == '#')
		arg->hastag = true;
	else if (c == '0')
		arg->zero = true;
	if (c == '-' ||
		c == '+' ||
		c == ' ' ||
		c == '#' ||
		c == '0')
		return (1);
	return (0);
}

int		extract_flags(char *ptr, t_arg *arg)
{
	int		i;

	i = 0;
	while (extra(ptr[i], arg) == 1)
		i++;
	return (i);
}
