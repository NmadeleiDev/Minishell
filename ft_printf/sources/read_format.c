/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_format.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:03:38 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/07 14:57:42 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		set_specif_s(t_ftprintf *specif)
{
	specif->wid = 0;
	specif->sign = '+';
	specif->pres = -42;
	specif->fill = ' ';
	specif->mod = '\0';
	if (!(specif->flag = ft_strnew(5)))
		emergency_exit();
	specif->conv = '\0';
}

int			read_format(va_list args, const char *conv, t_ftprintf *specif)
{
	int		i;

	i = 0;
	set_specif_s(specif);
	while (conv[i])
	{
		if (got_char("-+0 #", conv[i]))
			i += add_to_flag(specif, conv[i]);
		else if (ft_isdigit(conv[i]) || conv[i] == '*')
			i += add_to_wid(specif, (conv[i] == '*' ? \
			va_arg(args, int) : ft_atoi(&(conv[i]))), &(conv[i]));
		else if (conv[i] == '.')
			i += 1 + add_to_pres(specif, conv[i + 1] == '*' ? \
			va_arg(args, int) : ft_atoi(&(conv[i + 1])), &(conv[i + 1]));
		else if (got_char("hjlLtzw", conv[i]))
			i += add_to_mod(specif, conv[i], conv[i + 1]);
		else if (add_to_conv(specif, conv[i]))
			return (i);
		else
			return (i - 1);
	}
	return (-42);
}
