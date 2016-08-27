#include "myLib/mylib.h"
#include "fdf.h"

t_mesh	*matrix_to_mesh(t_matrix *m)
{
	t_mesh	*mesh;
	size_t	i;
	size_t	j;
	size_t	x;

	mesh = NULL;
	if (!(mesh = (t_mesh *)malloc(sizeof(t_mesh))))
		return (NULL);
	mesh->vert_nr = (m->x - 1) * m->y * 2;
	if (!(mesh->vert = (t_vector3 *)malloc(sizeof(t_vector3) * mesh->vert_nr)))
		return (NULL);
	i = 0;
	while (i < m->y)
	{
		j = 0;
		x = i * (m->x - 1) * 2;
		while (j < m->x - 1)
		{
			mesh->vert[x + (2 * j)] = (t_vector3){j, m->array[i][j], i};
			mesh->vert[x + (2 * j)+1]=(t_vector3){j + 1, m->array[i][j + 1], i};
			printf("%-3.0f", mesh->vert[x + (2 * j)].z);
			j += 1;
		}
		printf("%-3.0f", mesh->vert[x + (2 * j) - 1].z);
		printf("\n");
		i += 1;
	}
	printf("\n");
	mesh->primitive = gl_lines;
	return (mesh);
}


int		main(int argc, char **argv)
{
	t_matrix	*matrix;
	t_object	object;

	if (argc != 2)
		return (0);
	if (!(matrix = ft_read_file(argv[1])))
	{
		perror("Error: ");
		return (-1);
	}
	if (!(object.mesh = matrix_to_mesh(matrix)))
		return (ft_printf("mesh returned NULL\n"));
	object.rotat = (t_vector3){0.0, 0.0, 0.0};
	object.coord = (t_vector3){0.0, 0.0, 0.0};
	object.scale = 1.0;

	for (int y = 0; y < matrix->y; y++)
	{
		for (int x = 0; x < matrix->x; x++)
			printf("%-3d", matrix->array[y][x]);
		printf("\n");
	}
	printf("x = %zu\ny = %zu\n", matrix->x, matrix->y);
	return (0);
}
