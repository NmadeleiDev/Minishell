/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:58:19 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/26 12:39:56 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	if (dst == NULL || src == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		*(dst + i) = *(src + i);
		i++;
	}
	dst[i] = src[i];
	return (dst);
}
