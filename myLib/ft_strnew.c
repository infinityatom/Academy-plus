#include "mylib.h"

char	*ft_strnew(size_t size)
{
	void	*a;

	a = (char*)malloc(size);
	if (a == NULL)
		return (NULL);
	ft_memset(a, '\0', size);
	return (a);
}
