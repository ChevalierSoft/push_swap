/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:28:12 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/10 19:16:41 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	ra(t_game *g)
{
	void	*next_a;
	t_stack	*node;
	t_stack	*last_node;
	int		nb;


	if (!g->a || !g->a->next)
		return ;
	node = g->a;
	//nb = ft_lstcount(g->a->next);
	//node = ft_lstgetnb(g->a, nb - 1);
	//last_node = lstgetnb(nb);
	//printf("> node->content : %d\n", *((int *)node->content));
	
	g->a = g->a->next;
	node->next = NULL;
	ft_lstadd_back(&g->a, node);


}

