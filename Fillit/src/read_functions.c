/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:57:48 by rbodnare          #+#    #+#             */
/*   Updated: 2016/05/27 18:57:54 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	***extract_pieces(int i, int x, int y, int z)
{
	char	buf[SIZE_PIECES];
	char	***pieces;
	int		fd;

	if (!(pieces = alloc_three_d(19, 4, 4)))
		return (NULL);
	if (!(fd = open(PIECES, O_RDONLY)))
		return (NULL);
	if (!(read(fd, buf, SIZE_PIECES)))
		return (NULL);
	while (buf[i])
	{
		y = 0;
		while (buf[i] != '\n' && buf[i])
		{
			pieces[z][x][y] = buf[i];
			y++;
			i++;
		}
		i++;
		pieces[z][x][y] = '\0';
		x++;
		if (buf[i] == '\n')
		{
			x = 0;
			z++;
			i++;
		}
	}
	pieces[z][x - 1][y - 1] = '\0';
	return (pieces);
}

char	***extract_tetriminos(char *buf, int boxes, int *len)
{
	char	***pieces;
	char	***tet;
	int		i;
	int		j;

	j = 0;
	*len = 0;
	if (!(tet = (char ***)malloc(sizeof(char **) * boxes)))
		return (NULL);
	if (!(pieces = extract_pieces(0, 0, 0, 0)))
		return (NULL);
	while (boxes)
	{
		i = j;
		while (buf[i] != '#')
			i++;
		if (!(tet[*len] = check_type_tetrimino(buf, i, pieces)))
			return (NULL);
		*len += 1;
		j += 21;
		boxes--;
	}
	free_three_d(pieces, 4, 4);
	return (tet);
}

char	***read_the_tetriminos(char *file, int *len)
{
	char	***elem;
	char	buf[SIZE];
	int		boxes;
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	if (!read(fd, buf, SIZE))
		return (NULL);
	if (!(boxes = validate_boxes(buf)))
		return (NULL);
	if (!(elem = extract_tetriminos(buf, boxes, len)))
		return (NULL);
	if (close(fd) == -1)
		return (NULL);
	return (elem);
}
