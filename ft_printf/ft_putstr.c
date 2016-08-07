#include <unistd.h>

int		ft_putstr(char const *str)
{
	char *	str2;

	str2 = (char *)str;
	while (*str2)
	{
		write(1, str2, 1);
		str2 += 1;
	}
	return (str2 - str);
}
