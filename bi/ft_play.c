/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:46:04 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/28 16:03:47 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell_header.h"

int			main(void)
{
	char	command[256];
	int		i;

	i = 0;
	ft_putstr(ANSI_COLOR_RED "You wonna play?\n" ANSI_COLOR_RESET);
	while (ft_strequ(command, "yes") == 0)
	{
		ft_putstr("(say yes) ");
		ft_bzero(command, 256);
		read(STDIN_FILENO, &(command[i++]), 1);
		while (command[i - 1] != '\n')
			read(STDIN_FILENO, &(command[i++]), 1);
		if (command[i - 1] == '\n')
			command[i - 1] = '\0';
		i = 0;
	}
	ft_putstr(ANSI_COLOR_CYAN "Let's play!\n" ANSI_COLOR_RESET);
	return (0);
}
