/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:28:12 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/11 08:13:03 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	ra(t_game *g, int aff)
{
	t_stack	*node;

	if (!g->a || !g->a->next)
		return ;
	if (aff)
		ft_print("ra\n");
	node = g->a;
	g->a = g->a->next;
	node->next = NULL;
	ft_lstadd_back(&g->a, node);
	g->cpt++;
}
