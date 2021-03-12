/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:28:12 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/11 08:16:39 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	rra(t_game *g, int aff)
{
	t_stack	*node;

	if (!g->a || !g->a->next)
		return ;
	if (aff)
		ft_print("rra\n");
	node = ft_lstgetnb(g->a, ft_lstcount(g->a) - 2);
	node->next->next = g->a;
	g->a = node->next;
	node->next = NULL;
}

