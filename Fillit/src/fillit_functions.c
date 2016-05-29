/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:57:48 by rbodnare          #+#    #+#             */
/*   Updated: 2016/05/27 18:57:54 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	delete_last(s_fillit *obj, char **matrix, int l)
{
	int		x;
	int		y;

	y = 0;
	while (y < obj->min)
	{
		x = 0;
		while (x < obj->min)
		{
			if (matrix[y][x] == obj->str[l])
				matrix[y][x] = '.';
			x++;
		}
		y++;
	}
}

void	placeit(s_fillit *obj, s_coord coord, char **matrix, int l)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (obj->elem[l][0][i] != '#')
	{
		i++;
		coord.x--;
	}
	k = coord.x;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (obj->elem[l][j][i] == '#')
				matrix[coord.y][coord.x] = obj->str[l];
			i++;
			coord.x++;
		}
		j++;
		coord.y++;
		coord.x = k;
	}
}

int		can_be_placed(char **square, s_fillit *obj, s_coord coord, int l)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (obj->elem[l][0][i] != '#')
	{
		i++;
		coord.x--;
	}
	if (coord.x < 0)
		return (0);
	k = coord.x;
	j = 0;
	while (j < 4 && obj->elem[l][j][0])
	{
		if (coord.y >= obj->min)
			return (0);
		i = 0;
		while (i < 4 && obj->elem[l][j][i])
		{
			if (obj->elem[l][j][i] == '#' && square[coord.y][coord.x] != '.')
				return (0);
			if (coord.x >= obj->min)
				return (0);
			i++;
			coord.x++;
		}
		j++;
		coord.y++;
		coord.x = k;
	}
	return (1);
}

int		place(s_fillit *obj, char **matrix, int l)
{
	s_coord	coord;

	coord.y = 0;
	while (coord.y < obj->min)
	{
		coord.x = 0;
		while (coord.x < obj->min)
		{
			if (matrix[coord.y][coord.x] == '.')
			{
				if (can_be_placed(matrix, obj, coord, l))
				{
					placeit(obj, coord, matrix, l);
					return (1);
				}
			}
			coord.x++;
		}
		coord.y++;
	}
	return (0);
}

void	fillit(s_fillit *obj, char **matrix, int l)
{
	int		i;

	i = l;
	if (l == obj->len)
	{
		set_find(FOUND, 1);
		print_square(matrix, obj->min);
	}
	else
	{
		while (i < obj->len)
		{
			if (set_find(DID_FOUND, TO_FIND))
			{
				swap((obj->str + l), (obj->str + i));
				swap_2d((obj->elem[l]), (obj->elem[i]));
				if (place(obj, matrix, l))
				{
					fillit(obj, matrix, l + 1);
					delete_last(obj, matrix, l);
				}
				swap((obj->str + l), (obj->str + i));
				swap_2d((obj->elem[l]), (obj->elem[i]));
			}
			i++;
		}
	}
}
