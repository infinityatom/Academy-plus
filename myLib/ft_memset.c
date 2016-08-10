#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	w;

	p = (unsigned char *)b;
	w = (unsigned char)c;
	while (len > 0)
	{
		*p = w;
		p++;
		len--;
	}
	return (b);
}
