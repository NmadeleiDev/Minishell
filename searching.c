/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:07:15 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/29 13:06:36 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_header.h"

char		*return_found(char *name)
{
	if (access(name, X_OK) == 0)
		return (ft_strdup(name));
	else if (access(name, F_OK) == 0)
		return (no_file_c(&name, "Permission denied"));
	else
		return (no_file_c(&name, "command not found"));
}

char		*search_in_env(char *name, char *path)
{
	char	dirs[256];
	size_t	path_len;
	int		i;

	i = 0;
	ft_strcpy(path, &(ft_strchr(path, '=')[1]));
	path_len = ft_strlen(path);
	while (path_len > 0 && path != NULL)
	{
		ft_bzero(dirs, 256);
		ft_memccpy(dirs, path, ':', path_len);
		dirs[ft_strclen(dirs, ':')] = '/';
		ft_strcat(dirs, name);
		if (access(dirs, X_OK) == 0)
		{
			ft_strdel(&path);
			return (ft_strdup(dirs));
		}
		ft_strcpy(path, &((ft_strchr(path, ':'))[1]));
		path_len = ft_strlen(path);
	}
	ft_strdel(&path);
	return (return_found(name));
}

char		*get_variable(char *command, char **env_v)
{
	char	*tmp;

	tmp = grep_str_from_arr(env_v, &(command[1]));
	if (tmp == NULL)
		ft_printf("minishell: No such variable: %s", command);
	ft_strdel(&command);
	command = tmp;
	ft_memmove(command, &(command[ft_strclen(command, '=') + 1]),
	ft_strlen(command) - ft_strclen(command, '='));
	return (command);
}

void		sub_specials(char **command, char **env_v)
{
	char	*buf;
	char	*new;
	int		i;

	i = 1;
	while (command[i])
	{
		if (command[i][0] == '~' &&
		(ft_strlen(command[i]) == 1 || command[i][1] == '/'))
		{
			buf = grep_str_from_arr(env_v, "HOME");
			if (buf == NULL)
				return ;
			ft_strcpy(buf, ft_strchr(buf, '/'));
			ft_memmove(command[i], &(command[i][1]), ft_strlen(command[i]));
			new = ft_strjoin(buf, command[i]);
			ft_strdel(&buf);
			ft_strdel(&(command[i]));
			command[i] = new;
		}
		if (command[i][0] == '$')
			command[i] = get_variable(command[i], env_v);
		i++;
	}
}

char		*find_file(char **command, char **env_v)
{
	if (got_char(command[0], '/'))
	{
		if (access(command[0], F_OK) == 0 && access(command[0], X_OK) == 0)
			return (ft_strdup(command[0]));
		else
		{
			if (access(command[0], F_OK) == 0)
				no_file(command, "Permission denied");
			else
				no_file(command, "command not found");
			return (NULL);
		}
	}
	else
		return (search_in_env(command[0], grep_str_from_arr(env_v, "PATH")));
}
