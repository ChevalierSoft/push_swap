/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:28:12 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/10 18:20:03 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	pa(t_game *g, int aff)
{
	void	*next_b;

	if (!g->b)
		return ;
	if (aff)
		ft_print("pa\n");
	next_b = g->b->next;
	g->b->next = NULL;
	ft_lstadd_front(&g->a, g->b);
	g->b = next_b;
	g->cpt++;
}
