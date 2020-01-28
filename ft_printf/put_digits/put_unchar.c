/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:05:06 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/06 12:46:30 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/put_digits.h"

static unsigned char		countz(unsigned char i)
{
	unsigned char			del;

	del = 1;
	while (i / del >= 10)
		del = del * 10;
	return (del);
}

static unsigned char		count_mem_need(unsigned char del)
{
	unsigned char			count;
	unsigned char			i;

	count = 1;
	i = 1;
	while (del / i > 9)
	{
		count++;
		i = i * 10;
	}
	return (count);
}

char						*get_unchar(unsigned char n)
{
	char					*res;
	int						i;
	unsigned char			del;

	i = 0;
	del = 0;
	del = countz(n);
	if ((res = (char *)malloc(sizeof(char) * count_mem_need(del) + 1)) == NULL)
		return (NULL);
	res[0] = '-';
	while (del >= 1)
	{
		res[i++] = n / del + '0';
		n = n % del;
		del = del / 10;
	}
	res[i] = '\0';
	return (res);
}
