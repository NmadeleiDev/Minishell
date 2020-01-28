/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts_csp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:03:29 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/07 14:44:50 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*ft_no_free_malloc(char *s, char set_val, size_t n, int start)
{
	char		*tmp;

	if ((tmp = (char *)malloc(sizeof(char) * n + 1)) == NULL)
	{
		ft_putstr("error\n");
		exit(1);
	}
	ft_bzero(tmp, n + 1);
	ft_memset(tmp, set_val, n);
	if (start == 1)
		ft_memcpy(&tmp[n - (int)ft_strlen(s)], s, (int)ft_strlen(s));
	else
		ft_memcpy(tmp, s, (int)ft_strlen(s));
	return (tmp);
}

void			print_ptr(unsigned long long ptr, t_ftprintf *specif)
{
	char		*pref;
	char		*sptr;
	char		*num;
	int			ptr_len;

	num = get_lbase_num(ptr > 0 ? ptr : -ptr, 'x');
	if (ptr == 0 && specif->pres == 0)
		num[0] = '\0';
	ptr_len = ft_strlen(num);
	normalize_ptr(specif, ptr_len);
	if (!(pref = ft_strnew(specif->pres > ptr_len ? \
	specif->pres - ptr_len + 3 : 3)))
		emergency_exit();
	ft_memset(pref, '0', specif->pres > ptr_len ? \
	specif->pres - ptr_len + 2 : 2);
	ft_memcpy(pref, "0x", 2);
	sptr = ft_strjoin(pref, num);
	ft_strdel(&pref);
	ft_strdel(&num);
	ptr_len = ft_strlen(sptr);
	specif->out = specif->wid > ptr_len ? specif->wid : ptr_len;
	print_order(sptr, specif->wid, \
	got_char(specif->flag, '-'), specif->fill);
	ft_strdel(&sptr);
}

int				get_str_from_args(char **str, char conv, char **var)
{
	int			str_len;

	if (*str == NULL && conv == 's')
	{
		str_len = 6;
		if (!(*var = ft_strnew(7)))
			emergency_exit();
		ft_strcpy(*var, "(null)");
	}
	else
	{
		str_len = (conv == 's' ? (int)ft_strlen(*str) : 1);
		if (!(*var = ft_strnew(str_len + 1)))
			emergency_exit();
		conv == 's' ? ft_strcpy(*var, *str) : \
		ft_memcpy(*var, (char *)str, 1);
	}
	return (str_len);
}

void			put_cs(va_list args, t_ftprintf *specif)
{
	char		*str;
	char		*var;
	int			str_len;

	str = va_arg(args, char *);
	str_len = get_str_from_args(&str, specif->conv, &var);
	normalize_cs(specif);
	if (specif->pres < str_len && specif->pres >= 0 && specif->conv == 's')
	{
		ft_bzero(&(var[specif->pres]), str_len - specif->pres);
		str_len = specif->pres;
	}
	if (specif->wid > str_len)
	{
		var = ft_coolmalloc(var, specif->fill, \
		specif->wid, got_char(specif->flag, '-') ? 0 : 1);
		str_len = specif->wid;
		if (specif->conv == 'c')
			var[got_char(specif->flag, '-') ? 0 : specif->wid - 1] = (char)str;
	}
	write(1, var, str_len);
	specif->out = str_len;
	ft_strdel(&var);
}

void			put_groot(t_ftprintf *specif)
{
	if (got_char(specif->flag, '-'))
		specif->fill = ' ';
	specif->out = 1;
	if (specif->wid > 0)
	{
		specif->out = specif->wid;
		if (got_char(specif->flag, '-'))
		{
			ft_putchar('%');
			while (specif->wid-- > 1)
				ft_putchar(specif->fill);
		}
		else
		{
			while (specif->wid-- > 1)
				ft_putchar(specif->fill);
			ft_putchar('%');
		}
	}
	else
		ft_putchar('%');
}
