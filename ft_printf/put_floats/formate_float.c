/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formate_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:38:04 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/07 15:18:16 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int						plus_rests(char *rest, char *dev, int len)
{
	int					i;
	int					catch;

	i = 0;
	catch = 0;
	while (len >= 0)
	{
		rest[len] = rest[len] - 48 + dev[len] + catch;
		catch = 0;
		if (rest[len] > '9')
		{
			catch = 1;
			rest[len] -= 10;
		}
		len--;
	}
	return (catch);
}

void					manage_small_pres(t_floats *floa, t_ftprintf *specif)
{
	if (specif->pres == 0 && !got_char(specif->flag, '#'))
	{
		if (floa->rest && floa->rest[0] >= '5')
			increase_by_one(floa->mass, ft_strlen(floa->mass) - 1, 1);
		ft_bzero(floa->rest, ft_strlen(floa->rest));
	}
	else if (floa->rest != NULL && specif->pres < (int)ft_strlen(floa->rest))
	{
		if (floa->rest[specif->pres] >= '5' && \
		increase_by_one(floa->rest, specif->pres - 1, 0))
			increase_by_one(floa->mass, ft_strlen(floa->mass) - 1, 1);
		ft_memmove(&(floa->rest[1]), floa->rest, specif->pres);
		floa->rest[specif->pres + 1] = '\0';
		floa->rest[0] = '.';
	}
}

void					manage_huge_pres(t_floats *floa, t_ftprintf *specif)
{
	if (floa->rest)
	{
		floa->rest = ft_coolmalloc(floa->rest, '0', specif->pres + 1, 0);
		ft_memmove(&(floa->rest[1]), floa->rest, specif->pres);
	}
	else
	{
		if (!(floa->rest = ft_strnew(specif->pres + 2)))
			emergency_exit();
		ft_memset(floa->rest, '0', specif->pres + 1);
	}
	if (got_char(specif->flag, '#'))
		ft_bzero(floa->rest, ft_strlen(floa->rest));
	floa->rest[0] = '.';
}

void					formate_number(t_floats *floa, t_ftprintf *specif)
{
	if ((specif->pres == 0 && !got_char(specif->flag, '#')) || \
	(floa->rest != NULL && specif->pres < (int)ft_strlen(floa->rest)))
		manage_small_pres(floa, specif);
	else if (floa->rest == NULL || specif->pres >= \
	(int)ft_strlen(floa->rest) || got_char(specif->flag, '#'))
		manage_huge_pres(floa, specif);
	ft_strdel(&floa->whole);
	if (floa->rest && floa->rest[0])
		floa->whole = ft_strjoin(floa->mass, floa->rest);
	else
		floa->whole = ft_strdup(floa->mass);
	ft_strdel(&floa->rest);
	ft_strdel(&floa->mass);
}
