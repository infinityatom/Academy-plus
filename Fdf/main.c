#include "myLib/mylib.h"
#include "fdf.h"

int		main(int argc, char **argv)
{
	t_matrix	*matrix;

	if (argc != 2)
		return (0);
	if (!(matrix = ft_read_file(argv[1])))
	{
		perror("Error: ");
		return (-1);
	}
	printf("%d\n", matrix->array[0][1]);
	for (int y = 0; y < matrix->y; y++)
	{
		for (int x = 0; x < matrix->x; x++)
			printf("%d", matrix->array[y][x]);
		printf("\n");
	}
	return (0);
}
48
0
48
0
48
0
48
0
48
0
48
0
48
0
48
0
48
0
48
