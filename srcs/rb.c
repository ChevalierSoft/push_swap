/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:28:12 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/10 19:17:53 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	rb(t_game *g, int aff)
{
	t_stack	*node;

	if (!g->b || !g->b->next)
		return ;
	if (aff)
		ft_print("rb\n");
	node = g->b;
	g->b = g->b->next;
	node->next = NULL;
	ft_lstadd_back(&g->b, node);
	g->cpt++;
}
