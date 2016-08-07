#include <unistd.h>
#include <wchar.h>

int	ft_putwchar(wchar_t const c)
{
	write(1, &c, sizeof(wchar_t));
	return (1);
}
