#include "mylib.h"

int		ft_putfloat(float fl)
{
	char	*str;
	int		i;

	str = ft_ftoa(fl, 4);
	i = ft_putstr(str);
	free(str);
	return (i);
}
