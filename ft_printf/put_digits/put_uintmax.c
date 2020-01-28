/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_uintmax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:38:04 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/06 12:45:54 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/put_digits.h"

static uintmax_t		countz(uintmax_t i)
{
	uintmax_t			del;

	del = 1;
	while (i / del >= 10)
		del = del * 10;
	return (del);
}

static uintmax_t		count_mem_need(uintmax_t del)
{
	uintmax_t			count;
	uintmax_t			i;

	count = 1;
	i = 1;
	while (del / i > 9)
	{
		count++;
		i = i * 10;
	}
	return (count);
}

char					*get_uintmax_num(uintmax_t n)
{
	char				*res;
	int					i;
	uintmax_t			del;

	i = 0;
	del = countz(n);
	if ((res = (char *)malloc(sizeof(char) * count_mem_need(del) + 1)) == NULL)
		return (NULL);
	while (del >= 1)
	{
		res[i++] = n / del + '0';
		n = n % del;
		del = del / 10;
	}
	res[i] = '\0';
	return (res);
}
