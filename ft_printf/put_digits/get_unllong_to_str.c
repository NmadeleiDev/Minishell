/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_unllong_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:38:04 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/06 12:08:46 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/put_digits.h"

static unsigned long long	countz(unsigned long long i)
{
	unsigned long long		del;

	del = 1;
	while (i / del >= 10)
		del = del * 10;
	return (del);
}

static unsigned long long	count_mem_need(unsigned long long del)
{
	unsigned long long		count;
	unsigned long long		i;

	count = 1;
	i = 1;
	while (del / i > 9)
	{
		count++;
		i = i * 10;
	}
	return (count);
}

char						*get_unllong_to_str(unsigned long long n, char *str)
{
	int						str_len;
	int						i;
	int						num_len;
	unsigned long long		del;

	i = 0;
	str_len = ft_strlen(str);
	del = countz(n);
	num_len = count_mem_need(del);
	ft_memset(str, ' ', str_len - 1);
	while (del >= 1)
	{
		str[str_len - num_len + i] = n / del + '0';
		n = n % del;
		del = del / 10;
		i++;
	}
	str[str_len - num_len + i] = '\0';
	return (str);
}
