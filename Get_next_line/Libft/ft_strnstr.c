/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:57:48 by rbodnare          #+#    #+#             */
/*   Updated: 2016/05/27 18:57:54 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s1 && s2)
	{
		i = 0;
		j = 0;
		if (!*s2)
			return ((char*)s1);
		while (s1[i] && i < n)
		{
			while (s1[i] != s2[j] && s1[i])
				i++;
			str = (char*)&(s1[i]);
			while (s1[i] == s2[j] && s1[i] && s2[j] && i < n)
				i++, j++;
			if (!s2[j])
				return (str);
			else
				j = 0;
		}
	}
	return (NULL);
}
