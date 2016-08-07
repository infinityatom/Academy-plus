#include "ft_printf.h"

static int	extra(char *ptr, t_arg *arg)
{
	if (*ptr == 'h')
	{
		if (*ptr + 1 == 'h')
		{
			arg->length = hh;
			return (2);
		}
		arg->length = h;
		return (1);
	}
	if (*ptr == 'l')
	{
		if (*ptr + 1 == 'l')
		{
			arg->length = ll;
			return (2);
		}
		arg->length = l;
		return (1);
	}
	return (0);
}

int			extract_length(char *ptr, t_arg *arg)
{
	if (*ptr == 'j')
	{
		arg->length = j;
		return (1);
	}
	if (*ptr == 'z')
	{
		arg->length = z;
		return (1);
	}
	return (extra(ptr, arg));
}
