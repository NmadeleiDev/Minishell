/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:46:04 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/29 15:35:21 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_header.h"

int			main(void)
{
	char	**env_v;
	char	command[ARG_MAX];
	int		i;

	i = 0;
	env_v = environ_holder('c');
	ft_bzero(command, ARG_MAX);
	set_shell('s', "SHELL", grep_str_from_arr(env_v, "_="), env_v);
	while (read_comm(split_whitespaces(command)) > 0)
	{
		ft_putstr("$> ");
		ft_bzero(command, ARG_MAX);
		read(STDIN_FILENO, &(command[i++]), 1);
		while (command[i - 1] != '\n')
			read(STDIN_FILENO, &(command[i++]), 1);
		if (command[i - 1] == '\n')
			command[i - 1] = '\0';
		i = 0;
	}
	environ_holder('f');
	return (0);
}
