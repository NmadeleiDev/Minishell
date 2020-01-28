/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_str_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:38:04 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/07 13:28:06 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					double_str(char *num, int num_len)
{
	int					catch;

	catch = 0;
	while (num[num_len] != ' ')
	{
		num[num_len] = num[num_len] * 2 - 48 + catch;
		catch = 0;
		if (num[num_len] > '9')
		{
			catch = 1;
			num[num_len] -= 10;
		}
		num_len--;
	}
	if (catch != 0)
		num[num_len] = 49;
}

int						increase_num(char *num, int num_len)
{
	int					catch;

	num[num_len] = num[num_len] + 1;
	catch = 0;
	if (num[num_len] > '9')
	{
		catch = 1;
		num[num_len] = '0';
	}
	return (catch);
}

int						increase_by_one(char *num, int num_len, int trig)
{
	int					save_len;
	int					catch;

	catch = 1;
	save_len = num_len;
	while (catch != 0 && num_len >= 0)
	{
		catch = increase_num(num, num_len);
		num_len--;
	}
	if (num_len < 0 && catch == 1)
	{
		if (trig == 1)
		{
			ft_memset(num, '0', save_len + 1);
			num[0] = '1';
			num[save_len + 1] = '\0';
			return (1);
		}
		else
			return (1);
	}
	return (0);
}
