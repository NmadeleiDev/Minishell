/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_to_read_form.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:03:38 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/07 11:42:44 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			add_to_flag(t_ftprintf *specif, char c)
{
	if (!got_char(specif->flag, c))
		ft_strncat(specif->flag, &c, 1);
	if (c == '0')
		specif->fill = '0';
	return (1);
}

int			add_to_wid(t_ftprintf *specif, int wid, const char *str)
{
	int		i;

	i = 0;
	if (wid < 0)
	{
		wid = wid * (-1);
		add_to_flag(specif, '-');
	}
	specif->wid = wid;
	if (str[i] == '*')
		i = 1;
	else if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
			i++;
	}
	return (i);
}

int			add_to_pres(t_ftprintf *specif, int pres, const char *str)
{
	int		i;

	i = 0;
	specif->pres = 0;
	if (ft_isdigit(str[i]) || str[i] == '*')
	{
		specif->pres = pres;
		if (str[i] == '*')
			i = 1;
		else if (ft_isdigit(str[i]))
		{
			while (ft_isdigit(str[i]))
				i++;
		}
	}
	return (i);
}

int			add_to_mod(t_ftprintf *specif, char m, char m1)
{
	int		ret;

	if (m == m1 && ft_isalpha(m - 32))
	{
		ret = 2;
		m -= 32;
	}
	else
		ret = 1;
	if (got_char("HhzlLj", m) > got_char("HhzlLj", specif->mod))
		specif->mod = m;
	return (ret);
}

int			add_to_conv(t_ftprintf *specif, char c)
{
	if (got_char("cCdDiouUxXeEfFgGaAnpsS%%", c))
	{
		if (c == 'D' || c == 'U')
		{
			specif->mod = 'L';
			c += 32;
		}
		specif->conv = c;
		return (1);
	}
	else
	{
		specif->conv = '-';
		return (0);
	}
}
