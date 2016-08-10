#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*src;
	char		d;

	src = (const char *)s;
	d = c;
	while (n)
	{
		if (*src == d)
			return ((void *)src);
		src++;
		n--;
	}
	return (0);
}
