/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_base_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:38:04 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/07 14:17:54 by nmadelei         ###   ########.fr       */
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

unsigned int			jcount_mem_need(uintmax_t n, int del)
{
	unsigned int		count;

	count = 0;
	while (n >= 1)
	{
		n = n / del;
		count++;
	}
	return (count);
}

int						get_base(char base)
{
	if (base == 'x' || base == 'X')
		return (16);
	else if (base == 'o')
		return (8);
	else
		return (0);
}

char					*get_llbase_num(unsigned long long n, char base)
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

char					*get_lbase_num(unsigned long n, char base)
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
