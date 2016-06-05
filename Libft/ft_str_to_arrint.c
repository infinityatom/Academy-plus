/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_arrint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:57:48 by rbodnare          #+#    #+#             */
/*   Updated: 2016/05/27 18:57:54 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_str_to_arrint(char const *s)
{
	int		counter;
	int		len;
	int		*arr;
	int		i;

	len = ft_strword(s, ' ');
	if (!(arr = (int *)ft_memalloc(sizeof(int) * (len + 1))))
		return (NULL);
	counter = 0;
	i = 0;
	while (counter < len)
	{
		while (!(s[i] <= '9' && s[i] >= '0'))
			i++;
		arr[counter] = ft_atoi(s + i);
		counter++;
		while (s[i] <= '9' && s[i] >= '0')
			i++;
	}
	arr[counter] = '\0';
	return (arr);
}
