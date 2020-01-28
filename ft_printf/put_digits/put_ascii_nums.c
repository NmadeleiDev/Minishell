/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ascii_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:03:08 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/07 14:06:31 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			manage_num_flag(t_ftprintf *specif, \
char *num, char *flag, int i)
{
	int			flag_len;

	flag_len = ft_strlen(flag);
	if (flag_len > i)
	{
		ft_memmove(num, &(num[i]), ft_strlen(num));
		ft_putstr(flag);
		specif->out += flag_len;
	}
	else
	{
		if (!got_char(specif->flag, '-'))
			ft_memcpy(&(num[i - flag_len]), flag, flag_len);
		else if (num[i] == '\0' && specif->conv == 'o')
			ft_memcpy(num, flag, flag_len);
		else
		{
			specif->out += flag_len;
			ft_putstr(flag);
		}
	}
}

void			get_flag(char flag_type, char *repl_flag)
{
	if (flag_type == 'o')
		ft_strcpy(repl_flag, "0");
	else
	{
		if (flag_type == 'x')
			ft_strcpy(repl_flag, "0x");
		else
			ft_strcpy(repl_flag, "0X");
	}
}

void			add_sign(char *num, t_ftprintf *specif)
{
	int			i;
	int			flag_len;
	char		*repl_flag;

	if (!(repl_flag = ft_strnew(3)))
		emergency_exit();
	if (got_char("oxX", specif->conv) && got_char(specif->flag, '#'))
		get_flag(specif->conv, repl_flag);
	else if (!got_char("oxX", specif->conv))
		ft_strncpy(repl_flag, &(specif->sign), 1);
	i = 0;
	flag_len = (int)ft_strlen(repl_flag);
	while (num[i] == ' ' && num[i] != '\0')
		i++;
	if (!ft_strnstr(&(num[i]), repl_flag, flag_len))
	{
		if (i > 0)
			manage_num_flag(specif, num, repl_flag, i);
		else
		{
			specif->out += (int)ft_strlen(repl_flag);
			ft_putstr(repl_flag);
		}
	}
	ft_strdel(&repl_flag);
}

void			line_modifier(char *num, t_ftprintf *specif)
{
	if (specif->pres == 0 && num[0] == '0')
		ft_bzero(num, ft_strlen(num));
	if ((int)ft_strlen(num) < specif->wid)
		num = ft_coolmalloc(num, specif->fill, specif->wid, \
		got_char(specif->flag, '-') ? 0 : 1);
	if (got_char(" -#", specif->sign) || got_char(specif->flag, '+'))
		add_sign(num, specif);
	ft_putstr(num);
	specif->out += ft_strlen(num);
	if (num)
		ft_strdel(&num);
	if (specif->flag && (int)ft_strlen(specif->flag) > 0)
	{
		ft_strdel(&specif->flag);
		specif->flag = NULL;
	}
}
