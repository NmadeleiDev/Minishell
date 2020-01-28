/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_base_convs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:38:04 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/07 15:44:12 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/put_digits.h"

static int				count_mem_need(unsigned long long n, int del)
{
	int					count;

	count = 0;
	while (n >= 1)
	{
		n = n / del;
		count++;
	}
	return (count);
}

char					*getibase(unsigned int n, char base)
{
	char				*res;
	int					i;
	int					del;

	del = get_base(base);
	i = count_mem_need(n, del);
	if (!(res = ft_strnew(i + 1)))
		emergency_exit();
	i--;
	if (n == 0)
		res[0] = '0';
	while (n >= 1)
	{
		if (n % del > 9)
			res[i] = n % del + (base == 'X' ? 55 : 87);
		else
			res[i] = n % del + '0';
		n = n / del;
		i--;
	}
	return (res);
}

char					*get_hbase_num(unsigned short n, char base)
{
	char				*res;
	int					i;
	int					del;

	del = get_base(base);
	i = count_mem_need(n, del);
	if (!(res = ft_strnew(i + 1)))
		emergency_exit();
	i--;
	if (n == 0)
		res[0] = '0';
	while (n >= 1)
	{
		if (n % del > 9)
			res[i] = n % del + (base == 'X' ? 55 : 87);
		else
			res[i] = n % del + '0';
		n = n / del;
		i--;
	}
	return (res);
}

char					*get_hhbase_num(unsigned char n, char base)
{
	char				*res;
	int					i;
	int					del;

	del = get_base(base);
	i = count_mem_need(n, del);
	if (!(res = ft_strnew(i + 1)))
		emergency_exit();
	i--;
	if (n == 0)
		res[0] = '0';
	while (n >= 1)
	{
		if (n % del > 9)
			res[i] = n % del + (base == 'X' ? 55 : 87);
		else
			res[i] = n % del + '0';
		n = n / del;
		i--;
	}
	return (res);
}

char					*get_jbase_num(uintmax_t n, char base)
{
	char				*res;
	unsigned int		i;
	int					del;

	del = get_base(base);
	i = jcount_mem_need(n, del);
	if (!(res = ft_strnew(i + 1)))
		emergency_exit();
	i--;
	if (n == 0)
		res[0] = '0';
	while (n >= 1)
	{
		if (n % del > 9)
			res[i] = n % del + (base == 'X' ? 55 : 87);
		else
			res[i] = n % del + '0';
		n = n / del;
		i--;
	}
	return (res);
}
