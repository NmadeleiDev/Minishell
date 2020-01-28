/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:46:04 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/29 12:59:24 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_header.h"

int			ft_cd(int num, char **argv, char **env_v)
{
	char		*home;

	home = grep_str_from_arr(env_v, "HOME");
	if (home == NULL && (num == 1 || got_char(argv[1], '~')))
	{
		return (no_file(argv, "HOME enviroment variable is not set")
		+ freesher(argv));
	}
	if (num == 1)
	{
		if (chdir(ft_strchr(home, '/')) < 0)
			ft_printf("cd: not able to change directory: %s\n", argv[1]);
	}
	else if (num == 2)
	{
		sub_specials(argv, env_v);
		if (chdir(argv[1]) < 0)
			ft_printf("cd: no such file or directory: %s\n", argv[1]);
	}
	else if (num > 2)
		ft_printf("cd: string not in pwd: %s\n", argv[1]);
	freesher(argv);
	ft_strdel(&home);
	return (0);
}
