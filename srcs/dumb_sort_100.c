/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumb_sort_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:20:05 by dait-atm          #+#    #+#             */
/*   Updated: 2021/06/29 14:06:50 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

static inline
int	find_greatest(t_stack *sk)
{
	t_item	t;
	int		i;

	i = 0;
	t.p = 0;
	t.v = *((int *)sk->content);
	while (sk)
	{
		if (*((int *)sk->content) > t.v)
		{
			t.v = *((int *)sk->content);
			t.p = i;
		}
		i++;
		sk = sk->next;
	}
	return (t.p);
}

void	dumb_sort_100(t_game *g, int chunk_number)
{
	int	*q;
	int	i;

	q = malloc(sizeof(int) * chunk_number);
	if (!q)
		exit(6);
	get_n_limits(q, g, chunk_number);
	i = 0;
	while (i < chunk_number - 1)
	{
		push_chunk(g, q[i], chunk_number);
		i++;
	}
	push_chunk(g, q[chunk_number], chunk_number - 1);
	i = find_greatest(g->b);
	if (i)
	{
		if (i > ft_lstcount(g->b) / 2)
			i -= ft_lstcount(g->b);
		straff_to(g, i, &rb, &rrb);
	}
	while (g->b)
		pa(g, 1);
	free(q);
}
