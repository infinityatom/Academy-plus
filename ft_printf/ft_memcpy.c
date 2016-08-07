#include <stddef.h>

void	ft_memcpy(wchar_t *dst, wchar_t *src, size_t n)
{
	while (n > 0)
	{
		n -= 1;
		dst[n] = src[n];
	}
	dst[0] = src[0];
}
