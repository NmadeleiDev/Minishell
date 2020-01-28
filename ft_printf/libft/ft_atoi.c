/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:24:27 by nmadelei          #+#    #+#             */
/*   Updated: 2019/09/19 16:42:22 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(int sign)
{
	if (sign < 0)
		return (0);
	else
		return (-1);
}

static int	ft_sos(const char *str, int sign, int res)
{
	int		i;
	char	*test_long;

	test_long = "9223372036854775807";
	i = 0;
	if (str[19] >= '0' && str[19] <= '9')
		return (ft_sign(sign));
	while (i <= 18)
	{
		if (test_long[i] > str[i])
			return (res);
		else if (test_long[i] < str[i])
		{
			return (ft_sign(sign));
		}
		else
			i++;
	}
	return (res);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		sos;
	int		sign;
	int		res;

	res = 0;
	i = 0;
	sos = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\n' \
	|| str[i] == '\v' || str[i] == '\f' || str[i] == '\t')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && sos++ >= 0)
		res = res * 10 + (str[i++] - '0');
	if (sos > 18)
		return (ft_sos(&str[i - sos], sign, res));
	return (res * sign);
}
