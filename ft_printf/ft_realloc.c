#include "ft_printf.h"

wchar_t	*ft_realloc(wchar_t *ptr, size_t size_copy, size_t size_new, wchar_t c)
{
	wchar_t	*new_ptr;
	size_t	i;
	size_t	j;

	if ((new_ptr = (wchar_t *)malloc(sizeof(wchar_t) * (size_new + 1))) == NULL)
		return (NULL);
	i = 0;
	j = size_new - size_copy;
	while (i < j)
		new_ptr[i++] = c;
	ft_memcpy(new_ptr + j, ptr, size_copy);
	new_ptr[size_new] = '\0';
	free(ptr);
	return (new_ptr);
}
