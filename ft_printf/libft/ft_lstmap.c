/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:51:25 by nmadelei          #+#    #+#             */
/*   Updated: 2019/09/19 11:45:11 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nlst;
	t_list	*plst;

	if (lst == NULL || f == NULL)
		return (NULL);
	nlst = f(lst);
	plst = nlst;
	lst = lst->next;
	while (lst)
	{
		if (!(nlst->next = f(lst)))
			return (NULL);
		nlst = nlst->next;
		lst = lst->next;
	}
	return (plst);
}
