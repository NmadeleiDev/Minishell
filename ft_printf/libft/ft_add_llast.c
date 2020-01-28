/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_llast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:46:04 by nmadelei          #+#    #+#             */
/*   Updated: 2019/09/19 11:35:28 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_add_llast(t_list **alst, void *val)
{
	t_list	*tmp;

	tmp = *alst;
	if (tmp == NULL)
		return ;
	while (tmp->next)
		tmp = tmp->next;
	if ((tmp->next = (t_list *)malloc(sizeof(t_list))) != NULL)
	{
		tmp->next->content = val;
		tmp->next->content_size = sizeof(val);
	}
}
