/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:57:48 by rbodnare          #+#    #+#             */
/*   Updated: 2016/05/27 18:57:54 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_lines_in_file(char *argv)
{
	int		fd;
	int		i;
	int		j;
	char	buffer;

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (-1);
	j = 0;
	while (1)
	{
		if ((i = read(fd, &buffer, 1)) == -1)
			return (-1);
		if (buffer == '\n')
			j += 1;
		if (i == 0)
			break;
	}
	if (close(fd) == -1)
		return (-1);
	return (j);
}

int			**ft_read_file(char *argv, int **matrix)
{
	int		fd;
	int		v;
	int		i;
	char	*str;

	if ((i = ft_lines_in_file(argv)) == -1 ||
		(matrix = (int **)malloc(sizeof(int *) * (i))) == NULL ||
		(fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	i = 0;
	while ((v = get_next_line(fd, &str)) != 0)
	{
		if (v == -1)
		{
			ft_putstr("While reading ( with get_next_line ) an error ocured\n");
			return (NULL);
		}
		matrix[i] = ft_str_to_arrint(str);
		free(str);
		i++;
	}
	if (close(fd) == -1)
		return (NULL);
	return (matrix);
}
