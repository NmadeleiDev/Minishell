/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:51:01 by nmadelei          #+#    #+#             */
/*   Updated: 2019/09/20 11:00:04 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*temp;
	unsigned char	fill;

	fill = (unsigned char)c;
	i = 0;
	temp = b;
	while (i < len)
	{
		*(temp + i) = fill;
		i++;
	}
	return (b);
}
