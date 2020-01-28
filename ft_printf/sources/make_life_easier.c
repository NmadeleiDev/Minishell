/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_life_easier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:03:08 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/07 15:41:59 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		normalize_signed(t_ftprintf *specif)
{
	specif->out = 0;
	if ((got_char(specif->flag, '-') || specif->pres >= 0) \
	&& specif->fill == '0')
		specif->fill = ' ';
	if (got_char(specif->flag, ' ') && !got_char(specif->flag, '+') \
	&& specif->sign != '-')
		specif->sign = ' ';
	if (specif->wid > 0 && (got_char(specif->flag, '-') \
	|| specif->fill == '0') && \
	(specif->sign == '-' || specif->sign == ' ' || got_char(specif->flag, '+')))
		specif->wid--;
}

void		normalize_unsigned(t_ftprintf *specif)
{
	specif->out = 0;
	if (got_char(specif->flag, '-'))
		specif->flag[0] = '-';
	if (got_char(specif->flag, '+'))
		specif->flag[got_char(specif->flag, '+') - 1] = 'a';
	if (specif->pres >= 0 && specif->fill == '0')
		specif->fill = ' ';
	if (specif->wid > 0 && (got_char(specif->flag, '-') \
	|| specif->fill == '0') && \
	(specif->sign == '-' || specif->sign == ' ' || got_char(specif->flag, '+')))
		specif->wid--;
}

void		normalize_x(t_ftprintf *specif, char *num)
{
	specif->out = 0;
	specif->sign = '+';
	if ((got_char(specif->flag, '-') || specif->pres >= 0) \
	&& specif->fill == '0')
		specif->fill = ' ';
	if (got_char(specif->flag, '#'))
		specif->sign = '#';
	if (specif->sign == '#' && (int)ft_strlen(num) < specif->wid && \
	(got_char(specif->flag, '-') || specif->fill == '0'))
	{
		if (specif->conv == 'o')
		{
			if (num[0] == '0' || specif->fill == '0')
				specif->wid -= 0;
			else
				specif->wid -= 1;
		}
		else
			specif->wid -= 2;
	}
}

void		normalize_cs(t_ftprintf *specif)
{
	specif->out = 0;
	if (specif->fill == '0' && got_char(specif->flag, '-'))
		specif->fill = ' ';
}

void		normalize_ptr(t_ftprintf *specif, int ptr_len)
{
	if (specif->wid > ptr_len && specif->fill == '0')
	{
		specif->pres = specif->wid - 2;
	}
}
