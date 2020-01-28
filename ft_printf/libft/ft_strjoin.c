/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:10:05 by nmadelei          #+#    #+#             */
/*   Updated: 2019/09/17 13:44:21 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*baby;
	int		honey;
	int		jam;

	if (!(s1) || !(s2) || !(baby = (char *)malloc(sizeof(char) * \
	(ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	honey = 0;
	jam = 0;
	while (s1[honey] != '\0')
	{
		baby[honey] = s1[honey];
		honey++;
	}
	while (s2[jam] != '\0')
	{
		baby[honey] = s2[jam];
		honey++;
		jam++;
	}
	baby[honey] = '\0';
	return (baby);
}
