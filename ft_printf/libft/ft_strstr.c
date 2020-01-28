/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:26:27 by nmadelei          #+#    #+#             */
/*   Updated: 2019/09/20 11:00:04 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		j;
	int		i;
	int		nee_size;

	j = 0;
	i = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	nee_size = ft_strlen(needle);
	while (haystack[i] != '\0')
	{
		if (ft_memcmp(&haystack[i], needle, nee_size) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
