#include "mylib.h"

void	*ft_realloc(void *ptr, size_t size_copy, size_t size_add)
{
	void	*new_ptr;

	new_ptr = (void *)malloc(size_add + size_copy);
	if (new_ptr == NULL)
		return (NULL);
	new_ptr = ft_memcpy(new_ptr, ptr, size_copy);
	free(ptr);
	return (new_ptr);
}
