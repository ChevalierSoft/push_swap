/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_previous.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 08:23:21 by dait-atm          #+#    #+#             */
/*   Updated: 2021/02/16 08:23:26 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstget_previous(t_list *head, t_list *node)
{
	t_list	*n;

	n = head;
	while (n)
	{
		if (n->next == node)
			return (n);
		n = n->next;
	}
	return (NULL);
}
