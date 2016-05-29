/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:57:48 by rbodnare          #+#    #+#             */
/*   Updated: 2016/05/27 18:57:54 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	char *str1;
	char *str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (str1 && str2)
	{
		if (ft_strcmp(str1, str2) == 0)
			return (1);
		else
			return (0);
	}
	return (0);
}
