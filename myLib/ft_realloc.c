#include "mylib.h"

void	*ft_realloc(void *ptr, size_t size_o, size_t size_n)
{
	void	*new_ptr;

	new_ptr = (void *)malloc(size_o + size_n);
	if (new_ptr == NULL)
		return (NULL);
	new_ptr = ft_memcpy(new_ptr, ptr, size_n);
	free(ptr);
	return (new_ptr);
}
