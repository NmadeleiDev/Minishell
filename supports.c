/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supports.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:00:55 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/29 15:34:15 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_header.h"

int			no_file(char **file, char *error)
{
	ft_printf("minishell: %s: %s\n", error, *file);
	return (1);
}

char		*no_file_c(char **file, char *error)
{
	ft_printf("minishell: %s: %s\n", error, *file);
	return (NULL);
}

int			freesher(char **free_me)
{
	int		i;

	i = 0;
	if (free_me == NULL)
		return (1);
	while (free_me[i])
		ft_strdel(&(free_me[i++]));
	free(free_me);
	return (0);
}

void		*freeleak(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		ft_strdel(&(arr[i]));
		i++;
	}
	free(arr);
	return (NULL);
}

char		*grep_str_from_arr(char **arr, char *str)
{
	int		i;
	size_t	try_len;

	i = 0;
	if (arr == NULL || str == NULL)
		return (NULL);
	try_len = ft_strlen(str);
	while (arr[i])
	{
		if (ft_strnequ(arr[i], str, try_len))
			return (ft_strdup(arr[i]));
		i++;
	}
	return (NULL);
}
