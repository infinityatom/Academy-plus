#include "myLib/mylib.h"
#include "fdf.h"

int		main(int argc, char **argv)
{
	matrix	*matrix;

	if (argc != 2)
		return (0);
	if (!(matrix = ft_read_file(argv[1])))
	{
		perror("Error: ");
		return (-1);
	}
	return (0);
}
