/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:03:08 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/07 14:14:49 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_order(char *print_it, int wid, int order, char fill)
{
	int		str_len;

	str_len = ft_strlen(print_it);
	if (wid > str_len)
	{
		if (order > 0)
		{
			ft_putstr(print_it);
			while (wid-- > str_len)
				ft_putchar(fill);
		}
		else
		{
			while (wid-- > str_len)
				ft_putchar(fill);
			ft_putstr(print_it);
		}
	}
	else
		ft_putstr(print_it);
}
