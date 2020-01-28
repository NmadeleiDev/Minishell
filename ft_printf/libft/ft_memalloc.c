/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 15:42:32 by nmadelei          #+#    #+#             */
/*   Updated: 2019/09/20 13:44:04 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	if (size <= 0)
		return (NULL);
	str = malloc(size);
	if (str == NULL)
		return (NULL);
	while (size != 0)
		((char *)str)[--size] = 0;
	return (str);
}
