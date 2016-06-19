#include <unistd.h>

int		ft_putchar(char const c)
{
	write(1, &c, 1);
	return (1);
}
