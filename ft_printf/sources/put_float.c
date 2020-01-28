/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:03:51 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/06 12:03:53 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void		put_float(va_list args, t_ftprintf *specif)
{
	if (specif->mod == 'L')
		put_long_double(va_arg(args, long double), specif);
	else
		put_double(va_arg(args, double), specif);
}
