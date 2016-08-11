#include "myLib.h"
#include <unistd.h>

static int	ft_malloc_again(char **save, size_t buff_size)
{
	char	*tmp;

	if (!(tmp = ft_strnew(ft_strlen(*save))))
		return (0);
	ft_strcpy(tmp, *save);
	*save = NULL;
	if (!(*save = ft_strnew(ft_strlen(tmp) + buff_size)))
		return (0);
	ft_strcpy(*save, tmp);
	return (1);
}

static int	fill_line(int j, char **save, char **line)
{
	int		i;
	int		y;

	y = 0;
	i = 0;
	if (j != 0 || ft_strlen((*save)) != 0)
	{
		while ((*save)[i] != '\n')
		{
			(*line)[i] = (*save)[i];
			i++;
		}
		(*line)[i++] = '\0';
		if ((*save)[0] == '\n')
		{
			while ((*save)[i])
				(*save)[y++] = (*save)[i++];
			(*save)[y] = '\0';
			return (2);
		}
		while ((*save)[i])
			(*save)[y++] = (*save)[i++];
		(*save)[y] = '\0';
	}
	return (1);
}

int		get_next_line(int fd, char **line, size_t buff_size)
{
	static char	*save;
	int			j;

	if (fd < 0 || (!save && !(save = ft_strnew(buff_size))))
		return (-1);
	if (!(*line = (char *)malloc(sizeof(char) * buff_size)))
		return (-1);
	while ((j = read(fd, *line, buff_size)) > 0)
	{
		if (!(ft_malloc_again(&save, buff_size)))
			return (-1);
		ft_strncat(save, *line, buff_size);
		if (ft_memchr(*line, '\n', buff_size))
			break ;
	}
	if ((fill_line(j, &save, &(*line))) == 2)
		return (1);
	if (ft_memcmp((*line), save, ft_strlen(*line)) == 0)
	{
		if (!(*line = ft_strdup("")))
			return (1);
		return (0);
	}
	return (1);
}
