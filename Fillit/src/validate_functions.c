/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:57:48 by rbodnare          #+#    #+#             */
/*   Updated: 2016/05/27 18:57:54 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		compare_tetrimino(char *buf, char **piece, int n)
{
	int		i;
	int		j;

	i = 0;
	while (piece[0][i] != '#')
		i++;
	n -= i;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (piece[j][i])
		{
			if (piece[j][i] != buf[n])
				return (0);
			i++;
			n++;
		}
		n += 5 - i;
		j++;
	}
	return (1);
}

char	**check_type_tetrimino(char *buf, int i, char ***pieces)
{
	char		**piece;
	int			z;
	int			y;
	int			x;

	z = 0;
	while (z < 19)
	{
		if (compare_tetrimino(buf, pieces[z], i))
		{
			piece = alloc_two_d(4, 4);
			y = 0;
			while (y < 4)
			{
				x = 0;
				while (x < 4)
				{
					piece[y][x] = pieces[z][y][x];
					x++;
				}
				y++;
			}
			return (piece);
		}
		z++;
	}
	return (NULL);
}

int		validate_boxes(char *buf)
{
	int		i;
	int		k;
	int		n;
	int		j;

	j = 0;
	n = 0;
	k = 0;
	i = 0;
	while (buf[i])
	{
		j = 0;
		while (j < 4)
		{
			if (buf[i + j] != '.' && buf[i + j] != '#')
				return (0);
			if (buf[i + j] == '#')
				n += 1;
			j += 1;
		}
		i += j;
		if (++k % 4 == 0)
		{
			if (buf[i] != '\n' || n != 4)
				return (0);
			if (!buf[++i])
				return (k / 4);
			n = 0;
		}
		if (buf[i] != '\n')
			return (0);
		i++;
	}
	return (0);
}
