/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:58:19 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/27 11:22:13 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void					*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dest;
	unsigned const char	*srcs;

	i = 0;
	if (dst == NULL || src == NULL)
		return (NULL);
	if (len <= 0)
		return (dst);
	dest = (unsigned char*)dst;
	srcs = (unsigned const char*)src;
	if (len == 0)
		return (dst);
	if (dst > src)
	{
		while (len > 0)
		{
			*(dest + len - 1) = *(srcs + len - 1);
			len--;
		}
	}
	else
		ft_memcpy(dest, srcs, len);
	return (dst);
}
