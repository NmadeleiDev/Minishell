/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_nulled_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:51:01 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/07 09:56:00 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_new_nulled_str(size_t len)
{
	char	*new_str;

	new_str = ft_strnew(len);
	ft_memset(new_str, '0', len - 1);
	return (new_str);
}
