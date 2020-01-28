/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:52:24 by nmadelei          #+#    #+#             */
/*   Updated: 2019/09/13 22:18:30 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void		getzeros(int n, int fd)
{
	int			i;

	i = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	while (n % 10 == 0)
	{
		ft_putchar_fd('0', fd);
		n = n / 10;
	}
}

static void		nozeroes(int n, int del, int fd)
{
	if (n >= 0)
	{
		while (n > 0)
		{
			ft_putchar_fd(n / del + '0', fd);
			n = n % del;
			del = del / 10;
		}
	}
	else
	{
		while (n < 0)
		{
			ft_putchar_fd(n / del + '0', fd);
			n = n % del;
			if (n > 0)
				n = n * -1;
			del = del / 10;
		}
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	int			i;
	int			del;

	i = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i++;
	}
	del = countz(n);
	nozeroes(n, del, fd);
	getzeros(n, fd);
}
