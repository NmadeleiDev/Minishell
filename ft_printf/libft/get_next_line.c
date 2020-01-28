/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:22:58 by nmadelei          #+#    #+#             */
/*   Updated: 2019/10/07 12:43:59 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_coolmalloc(char *s, size_t n)
{
	char		*tmp;

	if ((tmp = (char *)malloc(sizeof(char) * n)) == NULL)
		return (NULL);
	ft_bzero(tmp, n);
	ft_memcpy(tmp, s, ft_strlen(s));
	if (s)
		free(s);
	return (tmp);
}

int				findsize(char *s)
{
	int			i;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}

int				ft_strccat(char *s1, char *s2, unsigned char c, size_t len)
{
	size_t		i1;
	size_t		i2;

	i1 = 0;
	i2 = 0;
	if (!ft_strlen(s2))
		return (0);
	while (s1[i1] != '\0')
		i1++;
	while (s2[i2] != '\0' && s2[i2] != c && i2 < len)
	{
		s1[i1] = s2[i2];
		i1++;
		i2++;
	}
	s1[i1] = '\0';
	if (s2[i2] == c)
		return (1);
	else
		return (0);
}

int				ft_cstrchr(char s[][BUFF_SIZE + 1], char c, char *check)
{
	int			i;
	int			a;
	int			res;

	a = 0;
	i = 0;
	if (ft_strlen(check) == 0 && (*s)[i] == 0)
		res = 0;
	else
		res = 1;
	while ((*s)[i] != c && (*s)[i] != '\0')
		i++;
	if ((*s)[i] == c)
	{
		i++;
		while ((*s)[i] != '\0')
			(*s)[a++] = (*s)[i++];
		ft_bzero(&((*s)[a]), BUFF_SIZE + 1 - a);
	}
	else
		ft_bzero(*s, BUFF_SIZE + 1);
	return (res);
}

int				get_next_line(const int fd, char **line)
{
	int			ird;
	static char	str[FD_MAX][BUFF_SIZE + 1];

	if (line == NULL || fd >= FD_MAX || fd < 0 || BUFF_SIZE > 65532)
		return (-1);
	if ((*line = (char *)malloc(sizeof(char) * (str[fd] ? \
	(findsize(str[fd]) + 1 + BUFF_SIZE) : BUFF_SIZE + 1))) == NULL)
		return (-1);
	ft_bzero(*line, (str[fd] ? (findsize(str[fd]) \
	+ 1 + BUFF_SIZE) : BUFF_SIZE + 1));
	if (ft_strccat(*line, str[fd], '\n', ft_strlen(str[fd])) == 1)
		return (ft_cstrchr(&(str[fd]), '\n', *line));
	ft_bzero(str[fd], BUFF_SIZE + 1);
	if ((ird = read(fd, str[fd], BUFF_SIZE)) < 0)
		return (-1);
	while (ird != 0 && ft_strccat(*line, str[fd], '\n', ird) \
	== 0 && ird == BUFF_SIZE)
	{
		ft_bzero(str[fd], BUFF_SIZE + 1);
		if ((ird = read(fd, str[fd], BUFF_SIZE)) < 0 || \
		(*line = ft_coolmalloc(*line, ft_strlen(*line) + ird + 1)) == NULL)
			return (-1);
	}
	return (ft_cstrchr(&(str[fd]), '\n', *line));
}
