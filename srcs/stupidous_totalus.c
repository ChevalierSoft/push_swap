/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stupidous_totalus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 03:02:25 by dait-atm          #+#    #+#             */
/*   Updated: 2021/07/06 03:25:21 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

static inline
int	find_lo_wang(t_game *g)
{
	t_stack	*a;
	int		min;
	int		pos;
	int		min_pos;

	a = g->a;
	min = *((int *)a->content);
	min_pos = 0;
	pos = 0;
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
	return (min_pos);
}

void	stupidous_totalus(t_game *g)
{
	int		min_pos;
	int		i;

	while (g->a)
	{
		min_pos = find_lo_wang(g);
		i = 0;
		while (i < min_pos)
		{
			ra(g, 1);
			i++;
		}
		pb(g, 1);
	}
	while (g->b)
		pa(g, 1);
}
