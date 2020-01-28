/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:38:34 by nmadelei          #+#    #+#             */
/*   Updated: 2019/09/19 16:38:35 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list		*ft_get_node(t_list **alst, int n)
{
	t_list	*rlst;
	int		i;

	rlst = *alst;
	i = 1;
	if (rlst == NULL)
		return (NULL);
	while (i < n)
	{
		rlst = rlst->next;
		i++;
		if (rlst == NULL)
			return (NULL);
	}
	return (rlst);
}
