#include "mylib.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst1;
	char	*src1;

	dst1 = (char*)dst;
	src1 = (char*)src;
	if (n & 1)
	{
		dst1[0] = src1[0];
		dst1 += 1;
		src1 += 1;
	}
	n /= 2;
	while (n--)
	{
		dst1[0] = src1[0];
		dst1[1] = src1[1];
		dst1 += 2;
		src1 += 2;
	}
	return (dst);
}
