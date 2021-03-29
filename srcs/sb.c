/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:28:12 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/29 10:29:23 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	sb(t_game *g, int aff)
{
	void	*ref;

	if (!g->b || !g->b->next)
		return ;
	if (aff)
		ft_print("sb\n");
	ref = g->b->content;
	g->b->content = g->b->next->content;
	g->b->next->content = ref;
	g->cpt++;
}
