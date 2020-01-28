/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:50:48 by nmadelei          #+#    #+#             */
/*   Updated: 2019/09/19 11:43:32 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nlst;

	if (*alst && del)
	{
		while (*alst)
		{
			nlst = (*alst)->next;
			ft_lstdelone(alst, del);
			(*alst) = nlst;
		}
		(*alst) = NULL;
	}
}
