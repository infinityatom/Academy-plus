/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:57:48 by rbodnare          #+#    #+#             */
/*   Updated: 2016/05/27 18:57:54 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	swap_2d_ext(char **a, char **b)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			a[i][j] = b[i][j];
			j++;
		}
		a[i][j] = '\0';
		i++;
	}
}

void	swap_2d(char **a, char **b)
{
	char	**c;

	c = alloc_two_d(4, 4);
	swap_2d_ext(c, a);
	swap_2d_ext(a, b);
	swap_2d_ext(b, c);
	free_two_d(c, 4);
}

void 	swap(char *a, char *b)
{
	int		t;

	t = *a;
	*a = *b;
	*b = t;
}
