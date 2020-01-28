/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:23:36 by nmadelei          #+#    #+#             */
/*   Updated: 2019/09/20 09:43:11 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		l_woutsp(char const *s, int *i)
{
	int			s_len;
	int			in;

	in = 0;
	s_len = ft_strlen(s) - 1;
	while ((s[s_len] == ' ' || s[s_len] == '\n'\
	|| s[s_len] == '\t') && s_len > 0)
		s_len--;
	while ((s[in] == ' ' || s[in] == '\n' || s[in] == '\t') && s[in] != '\0')
		in++;
	s_len = s_len - in + 1;
	*i = in;
	return (s_len);
}

char			*ft_strtrim(char const *s)
{
	char		*str;
	int			*i;
	int			b;
	int			st;
	int			s_len;

	b = 0;
	st = 0;
	i = &st;
	if (s == NULL)
		return (NULL);
	s_len = l_woutsp(s, i);
	if (s_len <= 0)
		return (ft_strnew(1));
	if ((str = (char *)malloc(sizeof(char) * s_len + 1)) == NULL)
		return (NULL);
	while (b < s_len)
	{
		str[b] = s[st];
		b++;
		st++;
	}
	str[b] = '\0';
	return (str);
}
