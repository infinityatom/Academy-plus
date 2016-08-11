#include "myLib.h"
#include <unistd.h>
#include <fcntl.h>

# define BUFF_SIZE 8

char	*ft_strchr(const char *s1, int c)
{
	if (s1 == NULL)
		return (0);
	while (*s1 != (char)c)
		if (!*s1++)
			return (0);
	return ((char *)s1);
}

char	*ft_strdup(const char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc (sizeof(dest) * ft_strlen(src) + 1);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int		gnl_check_stock(char **stock, char **line)
{
	char			*tmp;

	if ((tmp = ft_strchr(*stock, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(*stock);
		free(*stock);
		*stock = ft_strdup(tmp + 1);
		tmp = NULL;
		return (1);
	}
	return (0);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	if (s && n)
		ft_memset((unsigned char *)s, 0, n);
}

void	*ft_memalloc(size_t size)
{
	void	*nzone;

	if (!size)
		return (NULL);
	nzone = (void *)malloc(sizeof(void*) * size);
	if (!nzone)
		return (NULL);
	ft_bzero(nzone, size);
	return (nzone);
}

char	*ft_strnew(size_t size)
{
	char	*new;

	new = (char *)ft_memalloc(size + 1);
	if (new == NULL)
		return (NULL);
	else
		return (new);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char		*p_dest;
	const char	*p_src = src;

	p_dest = dest;
	while ((*p_dest++ = *p_src++))
		;
	*p_dest = '\0';
	return (dest);
}

char	*ft_strcat(char *s1, const char *s2)
{
	char		*p_s1;
	const char	*p_s2 = s2;

	p_s1 = s1;
	while (*p_s1)
		p_s1++;
	while ((*p_s1++ = *p_s2++))
		;
	*p_s1 = '\0';
	return (s1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	char		*new;

	s1 = (s1 == NULL) ? "" : s1;
	s2 = (s2 == NULL) ? "" : s2;
	if (s1 && s2)
	{
		i = ft_strlen(s1) + ft_strlen(s2);
		new = ft_strnew(i);
		if (new)
		{
			new = ft_strcpy(new, s1);
			new = ft_strcat(new, s2);
			return (new);
		}
	}
	return (NULL);
}

static int		gnl_check_read(char *buffer, char **stock, char **line)
{
	char			*tmp;

	if ((tmp = ft_strchr(buffer, '\n')))
	{
		*tmp = '\0';
		*line = ft_strjoin(*stock, buffer);
		free(*stock);
		*stock = ft_strdup(tmp + 1);
		tmp = NULL;
		free(buffer);
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char		*stock = NULL;
	char			*buffer;
	int				ret;

	if (stock)
		if (gnl_check_stock(&stock, line))
			return (1);
	buffer = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (gnl_check_read(buffer, &stock, line))
			return (1);
		stock = ft_strjoin(stock, buffer);
	}
	free(buffer);
	buffer = NULL;
	if (ret == -1)
		return (-1);
	if (stock == NULL)
		return (0);
	*line = ft_strdup(stock);
	free(stock);
	stock = NULL;
	return (0);
}
