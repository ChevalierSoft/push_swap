/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 02:26:17 by dait-atm          #+#    #+#             */
/*   Updated: 2020/12/31 17:48:00 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n;
	t_list	*head;

	if (!lst)
		return (NULL);
	n = ft_lstnew(f(lst->content));
	if (!n)
		return (NULL);
	head = n;
	while (lst->next)
	{
		lst = lst->next;
		n->next = ft_lstnew(f(lst->content));
		if (!n->next)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		n = n->next;
	}
	return (head);
}
