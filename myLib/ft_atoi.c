#include <stdio.h>

int		ft_atoi(char *str)
{
	int		nr;
	int		neg;

	neg = 1;
	if (*str == '-')
	{
		neg = -1;
		str += 1;
	}
	nr = 0;
	while (*str >= '0' && *str <= '9')
	{
		nr *= 10;
		nr += *str - '0';
		str += 1;
	}
	nr *= neg;
	return (nr);
}
