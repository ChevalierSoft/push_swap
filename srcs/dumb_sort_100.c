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

void	aff(char *name, int *d, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%s[%d] = %d\n", name, i, d[i]);
		i++;
	}
}

int	find_first_chunk(t_game *g, int l)
{
	t_stack	*a;
	int		n[2];
	int		i;

	a = g->a;
	n[0] = 0;
	n[1] = 0;
	i = 0;
	while (a)
	{
		if (*((int *)a->content) < l)
		{
			n[0] = i;
			break ;
		}
		i++;
		a = a->next;
	}
	n[1] = n[0];
	while (a)
	{
		if (*((int *)a->content) < l)
			n[1] = i;
		i++;
		a = a->next;
	}

	// printf("n0 : %d | n1 : %d\n", n[0], n[1]);
	if (n[0] > g->a_size / 2)
		n[0] -= g->a_size;
	if (n[1] > g->a_size / 2)
		n[1] -= g->a_size;
	// printf("n0 : %d | n1 : %d\n", n[0], n[1]);

	if (ft_abs(n[0]) - ft_abs(n[1]) == 0)
	{
		if (n[0] > 0)
			return (n[0]);
		else
			return (n[1]);
	}
	else if (ft_abs(n[0]) - ft_abs(n[1]) < 0)
			return (n[0]);
	else
		return (n[1]);
	
}

void	push_chunk(t_game *g, int limit)
{
	t_stack	*a;
	int		t;
	int		j;

	printf("g->a_initial_size : %d", g->a_initial_size);
	j = g->a_initial_size / N;
	a = g->a;
	while (j)
	{
		t = find_first_chunk(g, limit);
		// printf("t : %d\n", t);

		straff_to(g, t);
		pb(g, 1);
		j--;
	}
}

void	dumb_sort_100(t_game *g)
{
	int	q[N];

	get_n_limits(q, g);	// get N chunks limits
	// aff("q", q, N);

	push_chunk(g, q[0]);

	g->v = 1;
	display_lists(g);
}
