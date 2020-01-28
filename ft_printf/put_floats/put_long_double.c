/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_long_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:38:04 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/07 14:41:12 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			normalize_float(t_ftprintf *specif)
{
	specif->out = 0;
	if (got_char(specif->flag, ' ') && !got_char(specif->flag, '+') \
	&& specif->sign != '-')
		specif->sign = ' ';
	if (got_char(specif->flag, '-') && specif->fill == '0')
		specif->fill = ' ';
	if ((specif->sign == '-' || got_char(specif->flag, '+') \
	|| specif->sign == ' ') && \
	(got_char(specif->flag, '-') || specif->fill == '0'))
	{
		specif->wid--;
	}
	if (specif->pres < 0)
		specif->pres = 6;
}

static int		int128_itoa_2base(__uint128_t decim, char *based, int size)
{
	int			i;

	i = size - 1;
	while (i >= 0)
	{
		(based)[i] = decim % 2 + '0';
		decim = decim / 2;
		i--;
	}
	i = based[0] - '0';
	ft_memmove(based, &(based[1]), size);
	if (i == 1)
		return (1);
	else
		return (0);
}

void			convert_longbits_to_str(t_floats *floa, \
int exp, t_ftprintf *specif)
{
	if (!(floa->mass = ft_new_nulled_str(exp >= 0 ? (size_t)(exp + 2) : 2)))
		emergency_exit();
	if (exp >= 0 && exp < 64)
	{
		ft_strncpy(floa->mass, &(floa->whole[15]), exp + 1);
		floa->rest = ft_strsub(floa->whole, 16 + exp, 65 - exp);
	}
	else if (exp >= 64)
		ft_memcpy(floa->mass, &(floa->whole[15]), 64);
	else if (exp < 0)
	{
		if (!(floa->rest = ft_strnew(64 + exp * (-1))))
			emergency_exit();
		ft_memset(floa->rest, '0', exp * (-1));
		ft_strcat(floa->rest, &(floa->whole[16]));
		floa->rest[exp * (-1) - 1] = '1';
	}
	if (exp >= 0)
		convert_good_mass(floa->mass, exp, 63);
	floa->rest = convert_rest(floa->rest);
	formate_number(floa, specif);
	print_final_float(floa->whole, specif);
}

void			put_long_double(long double fl, t_ftprintf *specif)
{
	t_floats	floa;
	int			exp;
	char		sign;

	sign = '+';
	if (!(floa.whole = ft_strnew(81)))
		emergency_exit();
	floa.rest = NULL;
	normalize_float(specif);
	if (int128_itoa_2base(*((__uint128_t *)&fl), floa.whole, 80))
		sign = '-';
	else if (specif->sign == '+' && got_char(specif->flag, '+'))
		sign = '+';
	else if (specif->sign == ' ')
		sign = ' ';
	else
		sign = '\0';
	if (sign == '-' || sign == ' ')
		specif->wid--;
	specif->sign = sign;
	exp = (int)get_decim_out(floa.whole, 14) - 16383;
	convert_longbits_to_str(&floa, exp, specif);
}
