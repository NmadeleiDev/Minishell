/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:38:04 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/06 15:40:34 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/put_digits.h"

static unsigned long		countz(unsigned long i)
{
	unsigned long					del;

	del = 1;
	while (i / del >= 10)
		del = del * 10;
	return (del);
}

static unsigned long		count_mem_need(unsigned long del)
{
	unsigned long			count;
	unsigned long			i;

	count = 1;
	i = 1;
	while (del / i > 9)
	{
		count++;
		i = i * 10;
	}
	return (count);
}

char						*get_unlong(unsigned long n)
{
	char					*res;
	int						i;
	unsigned long			del;

	i = 0;
	del = 0;
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
