/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:44:05 by dait-atm          #+#    #+#             */
/*   Updated: 2020/12/31 18:35:18 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*r;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	r = malloc(ft_strlen(s) + 1);
	if (!r)
		return (0);
	while (s[i])
	{
		r[i] = f(i, s[i]);
		i++;
	}
	r[i] = 0;
	return (r);
}
