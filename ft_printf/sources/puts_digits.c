/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts_digits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:04:06 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/07 15:43:23 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

char			*ft_coolmalloc(char *s, char set_val, size_t n, int start)
{
	char		*tmp;

	if ((tmp = (char *)malloc(sizeof(char) * n + 1)) == NULL)
	{
		ft_putstr("error\n");
		exit(1);
	}
	ft_bzero(tmp, n + 1);
	ft_memset(tmp, set_val, n);
	if (ft_strlen(s) > 0)
	{
		if (start == 1)
			ft_memcpy(&tmp[n - ft_strlen(s)], s, ft_strlen(s));
		else
			ft_memcpy(tmp, s, ft_strlen(s));
	}
	ft_strdel(&s);
	return (tmp);
}

void			put_digit(va_list args, t_ftprintf *specif)
{
	if (specif->conv == 'i' || specif->conv == 'd' || specif->conv == 'D')
		sort_signed(args, specif);
	else if (specif->conv == 'u' || specif->conv == 'U')
		sort_unsigned(args, specif);
	else if (got_char("oxX", specif->conv))
		sort_calcs(args, specif);
}

void			sort_calcs(va_list args, t_ftprintf *specif)
{
	char		*num;

	num = NULL;
	if (specif->mod == '\0')
		num = getibase((unsigned int)va_arg(args, unsigned int), specif->conv);
	else if (specif->mod == 'l')
		num = get_lbase_num((unsigned long)\
		va_arg(args, unsigned long), specif->conv);
	else if (specif->mod == 'L')
		num = get_llbase_num((unsigned long long)\
		va_arg(args, unsigned long long), specif->conv);
	else if (specif->mod == 'h')
		num = get_hbase_num((unsigned short)\
		va_arg(args, unsigned int), specif->conv);
	else if (specif->mod == 'H')
		num = get_hhbase_num((unsigned char)\
		va_arg(args, unsigned int), specif->conv);
	else if (specif->mod == 'j')
		num = get_jbase_num((uintmax_t)va_arg(args, uintmax_t), specif->conv);
	if (num[0] == '0' && got_char(specif->flag, '#') && specif->conv != 'o')
		specif->flag[got_char(specif->flag, '#') - 1] = 'a';
	if ((int)ft_strlen(num) < specif->pres)
		num = ft_coolmalloc(num, '0', specif->pres, 1);
	normalize_x(specif, num);
	line_modifier(num, specif);
}

void			sort_signed(va_list args, t_ftprintf *specif)
{
	char		*num;

	num = NULL;
	if (specif->mod == '\0')
		num = get_int(va_arg(args, int));
	else if (specif->mod == 'H')
		num = get_schar((signed char)va_arg(args, int));
	else if (specif->mod == 'h')
		num = get_short((short)va_arg(args, int));
	else if (specif->mod == 'l')
		num = get_long(va_arg(args, long));
	else if (specif->mod == 'L' || specif->mod == 'z')
		num = get_llong(va_arg(args, long long));
	else if (specif->mod == 'j')
		num = get_intmax_num((intmax_t)va_arg(args, intmax_t));
	specif->sign = '-';
	if (num[0] == '-')
		ft_memmove(num, &num[1], ft_strlen(num));
	else
		specif->sign = '+';
	normalize_signed(specif);
	if ((int)ft_strlen(num) < specif->pres)
		num = ft_coolmalloc(num, '0', specif->pres, 1);
	line_modifier(num, specif);
}

void			sort_unsigned(va_list args, t_ftprintf *specif)
{
	char		*num;

	num = NULL;
	if (specif->mod == '\0')
		num = get_unint(va_arg(args, unsigned int));
	else if (specif->mod == 'H')
		num = get_unchar((unsigned char)va_arg(args, int));
	else if (specif->mod == 'h')
		num = get_unshort((unsigned short)va_arg(args, unsigned int));
	else if (specif->mod == 'l')
		num = get_unlong(va_arg(args, unsigned long));
	else if (specif->mod == 'L')
		num = get_unllong(va_arg(args, unsigned long long));
	else if (specif->mod == 'j')
		num = get_uintmax_num((uintmax_t)va_arg(args, uintmax_t));
	else if (specif->mod == 'z')
		num = get_size_t_num((size_t)va_arg(args, size_t));
	specif->sign = '+';
	normalize_unsigned(specif);
	if ((int)ft_strlen(num) < specif->pres)
		num = ft_coolmalloc(num, '0', specif->pres, 1);
	line_modifier(num, specif);
}
