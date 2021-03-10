/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:28:12 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/10 18:19:44 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	pb(t_game *g)
{
	void	*next_a;

	if (!g->a)
		return ;
	next_a = g->a->next;
	g->a->next = NULL;
	ft_lstadd_front(&g->b, g->a);
	g->a = next_a;
}
