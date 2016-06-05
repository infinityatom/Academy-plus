/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:57:48 by rbodnare          #+#    #+#             */
/*   Updated: 2016/05/27 18:57:54 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_two_d(char **data, char x)
{
	int		i;

	i = 0;
	while (i < x)
	{
		free(data[i]);
		i++;
	}
	free(data);
}

char	**alloc_two_d(char x, char y)
{
	char	**p;
	int		i;

	if (!(p = malloc(x * sizeof(*p))))
		return (NULL);
	i = 0;
	while (i < x)
		p[i++] = NULL;
	i = 0;
	while (i < x)
		if (!(p[i++] = malloc(sizeof(*p[i]) * (y + 1))))
		{
			free_two_d(p, x);
			return (NULL);
		}
	return (p);
}

void	free_three_d(char ***data, char x, char y)
{
	int		i;
	int		j;

	i = 0;
	while (i < x)
	{
		if (!data[i])
		{
			j = 0;
			while (j < y)
			{
				free(data[i][j]);
				i++;
			}
			free(data[i]);
		}
		i++;
	}
	free(data);
}

char	***alloc_three_d(char x, char y, char z)
{
	char	***p;
	int		i;

	if (!(p = malloc(x * sizeof(*p))))
		return (NULL);
	i = 0;
	while (i < x)
		p[i++] = NULL;
	i = 0;
	while (i < x)
		if (!(p[i++] = alloc_two_d(y, z)))
		{
			free_three_d(p, x, y);
			return (NULL);
		}
	return (p);
}

char	**alloc_matrix(char **matrix, int box)
{
	int		i;
	int		j;

	if (!(matrix = alloc_two_d(box, box)))
		return (NULL);
	i = 0;
	while (i < box)
	{
		j = 0;
		while (j < box)
		{
			matrix[i][j] = '.';
			j++;
		}
		matrix[i][j] = '\0';
		i++;
	}
	return (matrix);
}
