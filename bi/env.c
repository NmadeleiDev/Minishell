/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:46:04 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/28 16:38:02 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell_header.h"

void			null_env(char **env_v)
{
	int			i;

	i = 0;
	while (env_v[i] != NULL)
		env_v[i++] = NULL;
}

char			**create_args(char **arr)
{
	char		**argv;
	int			i;

	i = 0;
	while (arr[i])
		i++;
	argv = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (arr[i])
	{
		argv[i] = ft_strdup(arr[i]);
		i++;
	}
	argv[i] = NULL;
	return (argv);
}

int				set_env(char *arg, char **env_v)
{
	char		*tmp;

	tmp = ft_strsub(arg, 0, ft_strclen(arg, '='));
	set_shell('s', tmp, ft_strsub(arg,
	ft_strclen(arg, '='), ft_strlen(arg)), env_v);
	ft_strdel(&tmp);
	return (1);
}

int				main(int argc, char **argv)
{
	char		**env_v;
	int			i;

	i = 1;
	env_v = environ_holder('c');
	while (i < argc && !got_char(argv[i], '=') && argv[i][0] == '-')
	{
		if (got_char(argv[i], 'i'))
			null_env(env_v);
		if (argv[i][got_char(argv[i], 'u')] == '\0' && argv[i + 1] != NULL)
			set_shell('u', argv[++i], NULL, env_v);
		i++;
	}
	while (argv[i] && got_char(argv[i], '='))
		i += set_env(argv[i], env_v);
	if (argv[i] != NULL)
		read_comm(create_args(&(argv[i])));
	else
		ft_putarr(env_v, '\n');
	return (0);
}
