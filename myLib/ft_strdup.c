#include "mylib.h"

char	*ft_strdup(const char *s1)
{
	char	*new;

	new = (char *)malloc(ft_strlen(s1) + 1);
	if (new == NULL)
		return (NULL);
	ft_strcpy(new, s1);
	return (new);
}
