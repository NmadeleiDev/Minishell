/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:43:42 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/29 14:15:47 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numofs(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (s == NULL || ft_strlen(s) == 0)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			count++;
		}
	}
	return (count);
}

static int	getsize(char const *s, char c)
{
	int		a;

	a = 0;
	while (s[a] != '\0' && s[a] != c)
		a++;
	return (a);
}

static void	*freeleak(char **arr)
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

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		a;

	i = 0;
	a = 0;
	if (!(s) || numofs(s, c) == 0 || numofs(s, c) == 0 ||
	!(res = (char **)malloc(sizeof(char *) * (numofs(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			if ((res[a] = ft_strsub(s, i, getsize(&s[i], c))) == NULL)
				return (freeleak(res));
			i = i + getsize(&s[i], c);
			a++;
		}
	}
	res[a] = NULL;
	return (res);
}
