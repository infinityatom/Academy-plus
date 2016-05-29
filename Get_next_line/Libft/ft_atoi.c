/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:57:48 by rbodnare          #+#    #+#             */
/*   Updated: 2016/05/27 18:57:54 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int result;
	int negatif;

	result = 0;
	negatif = 0;
	if (str)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
			|| *str == '\f' || *str == '\v')
			str++;
		if (*str == '-')
		{
			negatif = 1;
			str++;
		}
		else if (*str == '+')
			str++;
		while (*str >= '0' && *str <= '9')
		{
			result += *str++ - '0';
			if (*str >= '0' && *str <= '9')
				result *= 10;
		}
	}
	return (negatif ? -result : result);
}
