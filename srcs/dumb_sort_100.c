/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumb_sort_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:20:05 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/30 08:24:51 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	dumb_sort_100(t_game *g)
{
	t_stack	*a;
	int		min;
	int		min_pos;
	int		pos;
	int		i;

	while (g->a)
	{
		a = g->a;
		min = *((int *)a->content);
		min_pos = 0;
		pos = 0;
		// get the min of a
		while (a)
		{
			if (*((int *)a->content) < min)
			{
				min = *((int *)a->content);
				min_pos = pos;
			}
			a = a->next;
			pos++;
		}
		// ra until the min found
		i = 0;
		while (i < min_pos)
		{
			ra(g, 1);
			i++;
		}
		// push it to b
		pb(g, 1);
	}
	while (g->b)
	{
		pa(g, 1);
	}
	display_lists(g);
}