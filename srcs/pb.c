/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:28:12 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/30 02:51:25 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	pb(t_game *g, int aff)
{
	void	*next_a;

	if (!g->a)
		return ;
	if (aff)
		ft_print("pb\n");
	next_a = g->a->next;
	g->a->next = NULL;
	ft_lstadd_front(&g->b, g->a);
	g->a = next_a;
	g->cpt++;
	g->a_size--;
}
