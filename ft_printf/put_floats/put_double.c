/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:38:04 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/07 14:45:18 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					printf_fill_sign(t_ftprintf *specif, int num_len)
{
	if (specif->fill == '0')
	{
		specif->out++;
		ft_putchar(specif->sign);
		while (specif->wid-- > num_len)
			ft_putchar(specif->fill);
	}
	else
	{
		while (specif->wid-- > num_len + 1)
			ft_putchar(specif->fill);
		ft_putchar(specif->sign);
	}
}

void					manage_printing_order(t_ftprintf *specif, \
char *finfloat, int num_len)
{
	specif->out += specif->wid;
	if (got_char(specif->flag, '-'))
	{
		if (got_char(specif->flag, '+') || \
		specif->sign == '-' || specif->sign == ' ')
		{
			specif->out++;
			ft_putchar(specif->sign);
		}
		write(1, finfloat, num_len);
		while (specif->wid-- > num_len)
			ft_putchar(' ');
	}
	else
	{
		if (got_char(specif->flag, '+') || \
		specif->sign == '-' || specif->sign == ' ')
			printf_fill_sign(specif, num_len);
		while (specif->wid-- > num_len)
			ft_putchar(specif->fill);
		ft_putstr(finfloat);
	}
}

void					print_final_float(char *finfloat, t_ftprintf *specif)
{
	int					num_len;

	num_len = (int)ft_strlen(finfloat);
	if (specif->wid > num_len)
		manage_printing_order(specif, finfloat, num_len);
	else
	{
		if (got_char(specif->flag, '+') || \
		specif->sign == '-' || specif->sign == ' ')
		{
			specif->out++;
			ft_putchar(specif->sign);
		}
		ft_putstr(finfloat);
		specif->out += ft_strlen(finfloat);
	}
	ft_strdel(&finfloat);
}

void					convert_bits_to_str(t_floats *floa, \
int exp, t_ftprintf *specif)
{
	if (exp >= 0 && exp < 52)
	{
		floa->mass[0] = '1';
		ft_strncpy(&(floa->mass[1]), &(floa->whole[11]), exp);
		floa->rest = ft_strsub(floa->whole, 11 + exp, 53 - exp);
		convert_good_mass(floa->mass, exp, 52);
	}
	else if (exp >= 52)
	{
		floa->mass[0] = '1';
		ft_memcpy(&(floa->mass[1]), &(floa->whole[11]), 52);
		convert_good_mass(floa->mass, exp, 52);
	}
	else if (exp < 0)
	{
		if (!(floa->rest = ft_strnew(52 + exp * (-1))))
			emergency_exit();
		ft_memset(floa->rest, '0', exp * (-1));
		ft_strcat(floa->rest, &(floa->whole[11]));
		floa->rest[exp * (-1) - 1] = '1';
	}
	floa->rest = convert_rest(floa->rest);
	formate_number(floa, specif);
	print_final_float(floa->whole, specif);
}

void					put_double(double fl, t_ftprintf *specif)
{
	t_floats			floa;
	int					exp;
	char				sign;

	sign = '+';
	if (!(floa.whole = ft_strnew(65)))
		emergency_exit();
	floa.rest = NULL;
	if (ft_itoa_2base(*((unsigned long long *)&fl), floa.whole, 64))
		sign = '-';
	else if (specif->sign == '+' && got_char(specif->flag, '+'))
		sign = '+';
	else
		sign = '\0';
	specif->sign = sign;
	normalize_float(specif);
	exp = (int)get_decim_out(floa.whole, 10) - 1023;
	if (!(floa.mass = ft_new_nulled_str(exp >= 0 ? (size_t)(exp + 2) : 2)))
		emergency_exit();
	convert_bits_to_str(&floa, exp, specif);
}
