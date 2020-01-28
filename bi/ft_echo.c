/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:46:04 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/29 15:42:28 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell_header.h"

int			is_flag(char *arg)
{
	int		i;

	i = 0;
	if (arg == NULL || arg[i++] != '-')
		return (0);
	else
	{
		while (arg[i])
		{
			if (arg[i] != 'n')
				return (0);
			i++;
		}
	}
	return (1);
}

int			main(int argc, char **argv)
{
	int		i;
	char	flag;
	int		pr_len;

	i = 1;
	pr_len = 0;
	flag = '\n';
	while (i++ < argc && is_flag(argv[i - 1]))
		flag = '\0';
	if (--i == argc)
		return (ft_printf("%s", flag));
	while (argv[i + 1])
		ft_printf("%s ", argv[i++]);
	ft_putstr(argv[i]);
	ft_putchar(flag);
	return (0);
}
