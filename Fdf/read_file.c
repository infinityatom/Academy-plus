#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "fdf.h"
#include "myLib/myLib.h"
#include "myGL/myGL.h"

int			**ct_realloci(int **ptr, size_t size_copy, size_t size_new)
{
	int		**new_ptr;
	size_t	i;

	if ((new_ptr = (int **)malloc(sizeof(int *) * size_new)) == NULL)
		return (NULL);
	i = 0;
	while (size_copy)
	{
		new_ptr[i] = ptr[i];
		i += 1;
	}
	free(ptr);
	return (new_ptr);
}

rgb			**ct_reallocr(rgb **ptr, size_t size_copy, size_t size_new)
{
	rgb		**new_ptr;
	size_t	i;

	if ((new_ptr = (rgb **)malloc(sizeof(rgb *) * size_new)) == NULL)
		return (NULL);
	i = 0;
	while (size_copy)
	{
		new_ptr[i] = ptr[i];
		i += 1;
	}
	free(ptr);
	return (new_ptr);
}

void		extract_vectors(int *array, rgb *color, char *line)
{
	size_t	i;

	i = 0;
	while (*line)
	{
		if (*line >= '0' && *line <= '9')
		{
			array[i] = ft_atoi(line) / 10;
			while (*line >= '0' && *line <= '9')
				line += 1;
			if (*line == ',')
			{
				line += 3;
				color[i] = str_to_rgb(line);
				line += 6;
			}
			else
				color[i] = 0;
			i += 1;
		}
		line += 1;
	}
}

int			extract_x(char *line)
{
	int		x;

	x = 0;
	if (*line >= '0' && *line <= '9')
		x = 1;
	while (*line)
	{
		if (*line == ' ')
		{
			x += 1;
			while (*line == ' ')
				line += 1;
		}
		line += 1;
	}
	return (x);
}

t_matrix	*ft_read_file(char *argv)
{
	t_matrix	*matrix;
	size_t		size;
	char		*line;
	int			fd;

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	if (get_next_line(fd, &line) == -1)
		return (NULL);
	if (!(matrix = (t_matrix *)malloc(sizeof(t_matrix))))
		return (NULL);
	matrix->x = extract_x(line);
	size = 50;
	matrix->array = (int **)malloc(sizeof(int *) * size);
	*matrix->array = (int *)malloc(sizeof(int) * matrix->x);
	matrix->color = (rgb **)malloc(sizeof(rgb *) * size);
	*matrix->color = (rgb *)malloc(sizeof(rgb) * matrix->x);
	extract_vectors(*matrix->array, *matrix->color, line);
	matrix->y = 1;
	while (get_next_line(fd, &line) == 1)
	{
		matrix->array[matrix->y] = (int *)malloc(sizeof(int) * matrix->x);
		matrix->color[matrix->y] = (rgb *)malloc(sizeof(rgb) * matrix->x);
		extract_vectors(matrix->array[matrix->y], matrix->color[matrix->y], line);
		matrix->y += 1;
		if (matrix->y == size)
		{
			size += 50;
			ct_realloci(matrix->array, matrix->y, size);
			ct_reallocr(matrix->color, matrix->y, size);
		}
	}
	if (close(fd) == -1)
		return (NULL);
	return (matrix);
}
