/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:46:04 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/29 16:20:12 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_header.h"

void		ft_setenv(char **argv, char **env_v)
{
	size_t	var_len;
	int		i;

	i = 0;
	if (argv[1] == NULL)
		ft_putarr(env_v, '\n');
	else if (argv[1])
	{
		var_len = ft_strlen(argv[1]);
		while (env_v[i++])
		{
			if (ft_strnequ(env_v[i - 1], argv[1], var_len)
			&& env_v[i - 1][var_len] == '=')
				break ;
		}
		if (env_v[--i] == NULL)
			env_v = environ_holder('e');
		else
			ft_strdel(&(env_v[i]));
		env_v[i] = ft_strnew(ft_strlen(argv[2]) + var_len + 2);
		ft_strcpy(env_v[i], argv[1]);
		ft_strcat(env_v[i], "=");
		if (argv[2])
			ft_strcat(env_v[i], argv[2]);
	}
}

int			ft_unsetenv(char **argv, char **env_v)
{
	size_t	var_len;
	int		i;

	i = 0;
	if (argv[1] == NULL)
		ft_printf("unsetenv: Too few arguments.\n");
	else if (argv[1])
	{
		var_len = ft_strlen(argv[1]);
		while (env_v[i])
		{
			if (ft_strnequ(env_v[i], argv[1], var_len)
			&& env_v[i][var_len] == '=')
				break ;
			i++;
		}
		while (env_v[i + 1])
		{
			ft_strdel(&(env_v[i]));
			env_v[i] = ft_strdup(env_v[i + 1]);
			i++;
		}
		ft_strdel(&(env_v[i]));
	}
	return (0);
}
