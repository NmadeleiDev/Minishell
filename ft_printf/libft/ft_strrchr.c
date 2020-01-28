/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:07:08 by nmadelei          #+#    #+#             */
/*   Updated: 2019/09/20 11:00:04 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	dad;
	char			*d;

	i = 0;
	dad = (unsigned char)c;
	d = (char*)s;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (d[i] == dad)
			return (&(d[i]));
		i--;
	}
	return (0);
}
