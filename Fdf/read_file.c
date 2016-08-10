#include <stdio.h>
#include <unistd.h>
#include "fdf.h"

matrix			*ft_read_file(char *argv)
{
	matrix	*matrix;
	int		fd;

	matrix = NULL;
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	if (close(fd) == -1)
		return (NULL);
	return (matrix);
}
