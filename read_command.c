/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:02:14 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/29 12:47:01 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_header.h"

int			try_buildins(char **command, char **env_v)
{
	int		i;

	i = 0;
	if (ft_strequ(command[0], "cd") == 1)
	{
		while (command[i])
			i++;
		ft_cd(i, command, env_v);
		return (1);
	}
	else if (ft_strequ(command[0], "setenv") == 1)
	{
		ft_setenv(command, env_v);
		freesher(command);
		return (1);
	}
	else if (ft_strequ(command[0], "unsetenv") == 1)
	{
		ft_unsetenv(command, env_v);
		freesher(command);
		return (1);
	}
	return (0);
}

int			check_command(char **command, char **env_v)
{
	if (command == NULL)
		return (1);
	else if (ft_strequ(*command, "exit") == 1)
		return (freesher(command));
	else if (try_buildins(command, env_v))
		return (1);
	else
		return (42);
}

int			read_comm(char **command)
{
	char	**env_v;
	char	*path;
	int		i;
	pid_t	pi;

	if (command == NULL)
		return (1);
	env_v = environ_holder('g');
	sub_specials(command, env_v);
	i = check_command(command, env_v);
	if (i != 42)
		return (i);
	path = find_file(command, env_v);
	if (path == NULL)
		return (freesher(command) + 1);
	pi = fork();
	if (pi == 0)
		execve(path, command, env_v);
	else if (pi < 0)
		exit(1);
	wait(NULL);
	ft_strdel(&path);
	freesher(command);
	return (1);
}

void		set_shell(char option, char *name, char *val, char **env_v)
{
	char	**make;

	make = (char **)malloc(sizeof(char *) * 4);
	make[0] = ft_strnew(256);
	option == 's' ? ft_strcpy(make[0], "setenv")
	: ft_strcpy(make[0], "unsetenv");
	make[1] = ft_strnew(256);
	ft_strcpy(make[1], name);
	if (option == 's')
	{
		make[2] = val;
		ft_strcpy(make[2], &(ft_strchr(make[2], '=')[1]));
		make[3] = NULL;
	}
	else
		make[2] = NULL;
	option == 's' ? ft_setenv(make, env_v) : ft_unsetenv(make, env_v);
	freesher(make);
}
