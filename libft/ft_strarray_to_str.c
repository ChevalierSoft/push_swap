/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarray_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:58:17 by dait-atm          #+#    #+#             */
/*   Updated: 2021/01/07 14:48:01 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strarray_to_str(char **ar)
{
	char	*s;
	int		i;

	if (!ar)
		return (NULL);
	s = strdup("/");
	if (!s)
		return (NULL);
	i = 0;
	while (ar[i])
	{
		ft_strjoin2(&s, ar[i]);
		if (!s)
			return (NULL);
		ft_strjoin2(&s, "/");
		if (!s)
			return (NULL);
		i++;
	}
	return (s);
}
