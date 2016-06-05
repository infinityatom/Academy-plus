/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:57:48 by rbodnare          #+#    #+#             */
/*   Updated: 2016/05/27 18:57:54 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_square(char **square, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			write(1, &square[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int		set_find(int action, int value)
{
	static int	var = 0;

	if (action == FIND)
	{
		var = value;
		return (var);
	}
	if (action == FOUND)
	{
		var -= value;
		return (var);
	}
	if (action == DID_FOUND)
		return (var);
	return (printf("error\n"));
}

int		min_box_size(int len)
{
	int		i;

	i = 0;
	len *= 4;
	while ((i * i) < len)
		i++;
	return (i);
}

int		prepare(char ***elem, int len, int min)
{
	s_fillit	obj;
	char		**matrix;
	int			i;

	i = 0;
	while (i < len)
		i++;
	if (!(obj.str = (char *)malloc(sizeof(char) * i)))
		return (0);
	i = 0;
	while (i < len)
	{
		obj.str[i] = 'A' + i;
		i++;
	}
	obj.str[i] = '\0';
	obj.elem = elem;
	obj.min = min;
	obj.len = len;
	matrix = NULL;
	if (!(matrix = alloc_matrix(matrix, min)))
		return (0);
	set_find(FIND, TO_FIND);
	fillit(&obj, matrix, 0);
	if (!set_find(DID_FOUND, TO_FIND))
		return (1);
	free_two_d(matrix, min);
	free(obj.str);
	return(prepare(elem, len, min + 1));
}

int		main(int argc, char **argv)
{
	char	***elem;
	int		min;
	int		len;

	if (argc != 2)
		return (printf("error 1\n"));
	if (!(elem = read_the_tetriminos(argv[1], &len)))
		return (printf("error 2\n"));
	if (!(min = min_box_size(len)))
		return (printf("error 3\n"));
	if (!prepare(elem, len, min))
		return (printf("error 4\n"));
	return (0);
}
