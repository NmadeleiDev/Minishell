/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:58:19 by nmadelei          #+#    #+#             */
/*   Updated: 2019/09/20 12:59:11 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	cha;
	unsigned char	*dest;
	unsigned char	*srcs;

	i = 0;
	cha = (unsigned char)c;
	dest = (unsigned char*)dst;
	srcs = (unsigned char*)src;
	while (i < n && srcs[i] != cha)
	{
		dest[i] = srcs[i];
		i++;
	}
	if (i == n)
		return (NULL);
	else
	{
		dest[i] = srcs[i];
		return (&(dst[i + 1]));
	}
}
