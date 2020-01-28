/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:38:04 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/06 12:08:58 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/put_digits.h"

static int		countz(int i)
{
	int			del;

	if (i >= 0)
		del = 1;
	else if (i < 0 && i >= -9)
		del = -1;
	else
		del = -10;
	while (i / del >= 10)
		del = del * 10;
	return (del);
}

static int		count_mem_need(int del)
{
	int			count;
	int			i;

	count = 1;
	if (del >= 0)
		i = 1;
	else
		i = -1;
	while (del / i > 9)
	{
		count++;
		i = i * 10;
	}
	return (count);
}

char			*get_int(int n)
{
	char		*res;
	int			mal;
	int			i;
	int			del;

	i = 0;
	mal = 0;
	del = 0;
	n < 0 ? mal++ : del++;
	del = countz(n);
	if (mal == 1)
		i++;
	mal = mal + count_mem_need(del);
	if ((res = (char *)malloc(sizeof(char) * mal + 1)) == NULL)
		return (NULL);
	res[0] = '-';
	while (del >= 1 || del <= -1)
	{
		res[i++] = n / del + '0';
		n = n % del;
		del = del / 10;
	}
	res[i] = '\0';
	return (res);
}
