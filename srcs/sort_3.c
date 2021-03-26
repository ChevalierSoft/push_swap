/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 05:34:21 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/26 08:23:32 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	sort_3(t_game *g)
{
	int a;
	int b;
	int c;

	a = *((int *)g->a->content);
	b = *((int *)g->a->next->content);
	c = *((int *)g->a->next->next->content);
	if (a < b && b < c)				// a < b < c
		return ;
	else if (a < c && c < b)		//a < c < b
	{
		sa(g, 1);
		ra(g, 1);
	}
	else if (b < a && a < c)		// b < a < c
		sa(g, 1);
	else if (b < c && c < a)		// b < c < a
		rra(g, 1);
	else if (c < a && a < b)		// c < a < b
		ra(g, a);
	else if (c < b && b < a)		// c < b < a
	{
		sa(g, 1);
		rra(g, 1);
	}
}

