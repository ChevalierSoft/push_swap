/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_str_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 11:51:03 by dait-atm          #+#    #+#             */
/*   Updated: 2021/01/12 16:07:23 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_realloc_str_array(char ***ar, unsigned int nb)
{
	char			**as;
	unsigned int	i;

	as = malloc(sizeof(char *) * (nb + 1));
	if (!as)
		return (NULL);
	i = 0;
	while (i < nb && (*ar)[i])
	{
		as[i] = (*ar)[i];
		i++;
	}
	as[i] = NULL;
	while ((*ar)[i])
	{
		free((*ar)[i++]);
	}
	free(*ar);
	return (as);
}
