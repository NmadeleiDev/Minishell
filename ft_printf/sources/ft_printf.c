/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:04:18 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/07 15:32:52 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "../includes/ft_printf.h"

void			emergency_exit(void)
{
	ft_putstr("error\n");
	exit(1);
}

int				got_char(char *str, char c)
{
	int			i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

int				put_replace(va_list args, t_ftprintf *specif, int *qout)
{
	if (got_char("diouUxX", specif->conv))
		put_digit(args, specif);
	else if (specif->conv == 'p')
		print_ptr(va_arg(args, unsigned long long), specif);
	else if (got_char("cs", specif->conv))
		put_cs(args, specif);
	else if (specif->conv == 'f')
		put_float(args, specif);
	else if (specif->conv == '%')
		put_groot(specif);
	else if (specif->conv == '-')
		specif->out = 0;
	*qout = -1;
	ft_strdel(&(specif->flag));
	return (specif->out);
}

int				check_format(const char *restrict *format, \
int *qout, int *i, int *count)
{
	*qout = 0;
	*i = 0;
	*count = 0;
	if (*format == NULL)
		return (0);
	else
		return (1);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		args;
	t_ftprintf	specif;
	int			qout;
	int			i;
	int			count;

	if (check_format(&format, &qout, &i, &count) == 0)
		return (0);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (qout > 0)
				count += write(1, &format[i - qout], qout);
			if ((qout = read_format(args, &(format[i + 1]), &specif)) == -42)
				return (count);
			i = i + qout + 1;
			count += put_replace(args, &specif, &qout);
		}
		i++;
		qout++;
	}
	va_end(args);
	return (count + write(1, &format[i - qout], qout));
}
