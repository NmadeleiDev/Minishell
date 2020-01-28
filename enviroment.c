/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:46:04 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/28 16:40:49 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_header.h"

char			**expand_env(char **env)
{
	char		**new;
	int			size;
	int			i;

	i = 0;
	while (env[i])
		i++;
	size = i;
	new = (char **)malloc(sizeof(char *) * (size + 2));
	i = 0;
	while (i < size)
	{
		new[i] = env[i];
		i++;
	}
	new[i] = NULL;
	new[i + 1] = NULL;
	free(env);
	return (new);
}

char			*dup_env(char *s2)
{
	extern char **environ;
	char		*home;
	char		*new;

	if (ft_strnequ(s2, "PATH=", 5) == 1)
	{
		home = grep_str_from_arr(environ, "PWD");
		new = ft_strnew(ft_strlen(s2) + 13 + ft_strlen(home));
		ft_strcpy(new, "PATH=");
		ft_strcat(new, &(home[4]));
		ft_strcat(new, "/bi:");
		ft_strcat(new, &(s2[5]));
		ft_strdel(&home);
	}
	else
		new = ft_strdup(s2);
	return (new);
}

char			**environ_holder(char option)
{
	extern char **environ;
	static char	**my_copy = NULL;
	int			vir_len;

	vir_len = 0;
	if (option == 'g')
		return (my_copy);
	else if (option == 'e')
		return (my_copy = expand_env(my_copy));
	else if (option == 'f')
	{
		freesher(my_copy);
		return (NULL);
	}
	while (environ[vir_len])
		vir_len++;
	my_copy = (char **)malloc(sizeof(char *) * (vir_len + 1));
	if (my_copy == NULL)
		exit(1);
	vir_len = 0;
	while (environ[vir_len++])
		my_copy[vir_len - 1] = dup_env(environ[vir_len - 1]);
	my_copy[vir_len - 1] = NULL;
	return (my_copy);
}
