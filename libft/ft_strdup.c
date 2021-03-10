/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:18:37 by dait-atm          #+#    #+#             */
/*   Updated: 2021/01/07 17:56:35 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*r;
	size_t	sz;

	sz = ft_strlen(s1) + 1;
	r = malloc(sz);
	if (!r)
		return (0);
	return (ft_memcpy(r, s1, sz));
}
