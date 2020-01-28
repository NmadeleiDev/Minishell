/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:46:07 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/26 13:14:19 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (((char *)s)[i] != '\0')
	{
		if (((char *)s)[i] == (unsigned char)c)
			return (&(((char *)s)[i]));
		i++;
	}
	if (((char *)s)[i] == '\0')
		return (&(((char *)s)[i]));
	return (NULL);
}
