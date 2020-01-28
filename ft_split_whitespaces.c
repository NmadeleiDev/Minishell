/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:46:04 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/29 16:09:56 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_header.h"

int			skip_word(char *str)
{
	char	match;
	int		i;

	i = 0;
	if (str == NULL)
		return (-42);
	while (str[i] && str[i] != ' ' && str[i] != '\t')
	{
		if (str[i] == 39 || str[i] == 34)
		{
			match = str[i++];
			while (str[i] != '\0' && str[i++] != match)
				;
			if (str[i] == '\0' && str[i - 1] != match)
				return (-42);
		}
		else
			i++;
	}
	return (i);
}

int			count_words(char *str)
{
	int		res;
	int		i;

	res = 0;
	i = 0;
	while (str && str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			res++;
			if (skip_word(&(str[i])) < 0)
			{
				ft_printf("minishell: No matching qoute.\n");
				return (0);
			}
			i += skip_word(&(str[i])) - 1;
		}
		i++;
	}
	return (res);
}

char		*trim_qoutes(char *str)
{
	int		i;
	int		j;
	int		new_len;
	char	match;
	char	*res;

	i = 0;
	j = 0;
	new_len = ft_strlen(str);
	res = ft_strnew(new_len);
	while (i < new_len)
	{
		if (str[i] && (str[i] == 39 || str[i] == 34))
		{
			match = str[i++];
			while (str[i] && str[i] != match)
				res[j++] = str[i++];
			i++;
		}
		else
			res[j++] = str[i++];
	}
	ft_strdel(&str);
	return (res);
}

char		*get_word(char *str)
{
	char	*word;
	int		i;

	i = skip_word(str);
	word = ft_strsub(str, 0, i);
	if (word == NULL)
		return (NULL);
	else
		return (trim_qoutes(word));
}

char		**split_whitespaces(char *str)
{
	char	**splited;
	int		i;
	int		j;
	int		num_of_words;

	i = 0;
	j = 0;
	num_of_words = count_words(str);
	if (num_of_words == 0 || ft_strlen(str) == 0)
		return (NULL);
	splited = (char **)malloc(sizeof(char *) * (num_of_words + 1));
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			if ((splited[j++] = get_word(&(str[i]))) == NULL)
				return (freeleak(splited));
			i += skip_word(&(str[i])) - 1;
		}
		i++;
	}
	splited[j] = NULL;
	return (splited);
}
