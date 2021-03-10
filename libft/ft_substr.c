/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:06:54 by dait-atm          #+#    #+#             */
/*   Updated: 2020/12/31 18:44:06 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (!s)
		return (0);
	p = malloc(sizeof(char) * len + 1);
	if (!p)
		return (0);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (len-- && s[i])
		{
			p[i] = s[i + start];
			i++;
		}
	}
	p[i] = 0;
	return (p);
}
