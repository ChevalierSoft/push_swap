/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:28:12 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/11 08:18:33 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	rrb(t_game *g, int aff)
{
	t_stack	*node;

	if (!g->b || !g->b->next)
		return ;
	if (aff)
		ft_print("rrb\n");
	node = ft_lstgetnb(g->b, ft_lstcount(g->b) - 2);
	node->next->next = g->b;
	g->b = node->next;
	node->next = NULL;
}

