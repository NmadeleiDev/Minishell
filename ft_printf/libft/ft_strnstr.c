/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:22:43 by nmadelei          #+#    #+#             */
/*   Updated: 2019/09/20 12:59:11 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		nee_size;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	nee_size = ft_strlen(needle);
	while (haystack[i] != '\0' && i + nee_size - 1 < len)
	{
		if (ft_memcmp(&haystack[i], needle, nee_size) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
