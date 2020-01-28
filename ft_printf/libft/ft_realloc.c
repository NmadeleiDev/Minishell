/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:38:02 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/28 19:34:47 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_realloc(char *s, size_t size)
{
	char	*tmp;

	tmp = ft_strnew(size);
	if (tmp == NULL)
		return (NULL);
	ft_strcpy(tmp, s);
	ft_strdel(&s);
	return (tmp);
}
