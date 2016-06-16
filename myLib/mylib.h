/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbodnare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/31 18:59:42 by rbodnare          #+#    #+#             */
/*   Updated: 2015/10/31 18:59:51 by rbodnare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_printf(const char * restrict format, ...);
void	*ft_realloc(void *ptr, size_t size_o, size_t size_n);
size_t	ft_strlen(const char *s);

#endif
