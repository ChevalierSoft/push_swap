/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 02:26:28 by dait-atm          #+#    #+#             */
/*   Updated: 2020/12/31 17:49:51 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *v)
{
	t_list	*n;

	n = malloc(sizeof(t_list));
	if (!n)
	{
		write(1, "not enough space\n", 16);
		return (NULL);
	}
	n->content = v;
	n->next = NULL;
	return (n);
}
