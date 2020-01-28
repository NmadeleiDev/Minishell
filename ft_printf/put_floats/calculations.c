/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:38:04 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/07 15:20:40 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					dev_dev_part(char *num, int num_len)
{
	int					catch;
	int					i;

	catch = 0;
	i = 0;
	ft_memmove(&(num[1]), num, num_len);
	num[0] = '0';
	while (num_len >= 0)
	{
		num[num_len] = (num[num_len] - 48) * 5 + 48 + catch;
		catch = 0;
		if (num[num_len] > '9')
		{
			catch = (num[num_len] - 48) / 10;
			num[num_len] = (num[num_len] - 48) % 10 + 48;
		}
		num_len--;
	}
}

unsigned long long		get_decim_out(char *based, int len)
{
	unsigned long long	res;
	int					pows;

	pows = 1;
	res = 0;
	while (len >= 0)
	{
		if (based[len] == '1')
			res = res + pows;
		pows = pows * 2;
		len--;
	}
	return (res);
}

int						ft_itoa_2base(unsigned long long decim, \
char *based, int size)
{
	int					i;

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

void					convert_good_mass(char *mass, int exp, int size)
{
	int					i;
	unsigned long long	res;

	i = 1;
	res = 1;
	while (i <= size && mass[i] != '\0')
	{
		if (mass[i] == '0')
			res = res * 2;
		else
			res = res * 2 + 1;
		i++;
	}
	get_unllong_to_str(res, mass);
	while (exp - i + 1 != 0)
	{
		double_str(mass, exp);
		i++;
	}
	i = 0;
	while (!ft_isdigit(mass[i]))
		i++;
	ft_memmove(mass, &(mass[i]), exp - i + 2);
}

char					*convert_rest(char *num)
{
	char				*rest;
	char				*dev;
	int					i;

	if (num == NULL)
		return (NULL);
	i = 0;
	if (!(rest = ft_strnew(ft_strlen(num) + 1)))
		emergency_exit();
	if (!(dev = ft_strnew(ft_strlen(num) + 1)))
		emergency_exit();
	ft_memset(rest, '0', ft_strlen(num));
	ft_memcpy(dev, "5", 1);
	while (num[i] != '\0')
	{
		if (num[i] == '1')
			plus_rests(rest, dev, i);
		i++;
		dev_dev_part(dev, i);
	}
	ft_strdel(&num);
	ft_strdel(&dev);
	return (rest);
}
