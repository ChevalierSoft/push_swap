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
		// printf("%s[%d] = %d\n", name, i, d[i]);
		i++;
	}
}

int	find_first_chunk(t_game *g, int limit)
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
		if (*((int *)a->content) < limit)
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
		if (*((int *)a->content) < limit)
			n[1] = i;
		i++;
		a = a->next;
	}
	// g->a_size = ft_lstcount(g->a);
	// printf("n0 : %d | n1 : %d\n", n[0], n[1]);

	// if (n[0] > (g->a_size / 2) + ( 1 - g->a_size % 2))
	// 	n[0] -= g->a_size + (1 - g->a_size % 2);
	// if (n[1] > (g->a_size / 2) + (1 - g->a_size % 2))
	// 	n[1] -= (g->a_size)+ (1 - g->a_size % 2);
	if (n[0] > (g->a_size / 2))
		n[0] -= g->a_size;
	if (n[1] > (g->a_size / 2))
		n[1] -= g->a_size;
	// printf("n0 : %d | n1 : %d\n", n[0], n[1]);

	if (ft_abs(n[0]) - ft_abs(n[1]) == 0)
	{
		if (n[0] >= 0)
			return (n[0]);
		else
			return (n[1]);
	}
	else if (ft_abs(n[0]) - ft_abs(n[1]) < 0)
			return (n[0]);
	else
		return (n[1]);
	
}

void	greatest_lowest_item(t_stack *sk, t_item *greatest, t_item *lowest)
{
	int	i;

	i = 0;
	greatest->p = i;
	greatest->v = *((int *)sk->content);
	lowest->p = i;
	lowest->v = greatest->v;
	while (sk)
	{
		if (*((int *)sk->content) > greatest->v)
		{
			greatest->v = *((int *)sk->content);
			greatest->p = i;
		}
		else if (*((int *)sk->content) < lowest->v)
		{
			lowest->v = *((int *)sk->content);
			lowest->p = i;
		}
		i++;
		sk = sk->next;
	}
}

int	roll_lowest_greatest(t_game *g, t_item *lowest, t_item *greatest, int t)
{
	t_stack	*b;
	int		pos;

	// get the real greatest/lowest
	greatest_lowest_item(g->b, greatest, lowest);

	// if t > greatest keep greatest
	// if t < lowest keep lowest
	if (t > greatest->v)
	{
		// printf("t(%d) > gr->v(%d)\n", t, greatest->v);
		return (greatest->p);
	}
	else if (t < lowest->v)
	{
		// printf("t(%d) < lo->v(%d)\n", t, lowest->p);
		return (greatest->p);
	}

	b = g->b;
	pos = 0;
	while (b)
	{
		if (*((int *)b->content) > lowest->v && *((int *)b->content) < t)
		{
			lowest->v = *((int *)b->content);
			lowest->p = pos;
		}
		// else if (*((int *)b->content) < greatest->v && *((int *)b->content) >= t)
		// {
		// 	greatest->v = *((int *)b->content);
		// 	greatest->p = pos;
		// }
		b = b->next;
		pos++;
	}
	// printf("lowest : v = %d, p = %d\n", lowest->v, lowest->p);
	// printf("greatest : v = %d, p = %d\n", greatest->v, greatest->p);
	// if (greatest->p <= lowest->p)
	// 	return (greatest->p);
	// else
	// 	return (lowest->p);
	return (lowest->p);
}

void	push_chunk(t_game *g, int limit, int chunk_number)
{
	t_stack	*a;
	int		t;
	int		j;
	t_item	lowest;
	t_item	greatest;
	t_stack	*n;
	int		t2;
	int		b_size;


	// g->v = 1;
	// display_lists(g);

	j = g->a_initial_size / chunk_number;
	a = g->a;
	while (j && g->a)
	{
		t = find_first_chunk(g, limit);
		// printf("t : %d\n", t);

		if (g->b)
		{
			if (t < 0)
			{
				t += g->a_size;
				n = ft_lstgetnb(g->a, t);
				t -= g->a_size;
			}
			else
				n = ft_lstgetnb(g->a, t);
			t2 = roll_lowest_greatest(g, &lowest, &greatest, *((int *)n->content));

			b_size = ft_lstcount(g->b);
			if (t2 > b_size / 2)
				t2 -= b_size;
			// printf("t : %d | t2 : %d\n", t, t2);

			while (t < 0 && t2 < 0)
			{
				rrr(g, 1);
				t++;
				t2++;
			}
			while (t > 0 && t2 > 0)
			{
				rr(g, 1);
				t--;
				t2--;
			}
			straff_to(g, t, &ra, &rra);
			straff_to(g, t2, &rb, &rrb);
			g->v = 1;
			// display_lists(g);
		}
		else
			straff_to(g, t, &ra, &rra);

		pb(g, 1);
		j--;

		// g->v = 1;
		// display_lists(g);
	}
}

int find_greatest(t_stack *sk)
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

	if (!(q = malloc(sizeof(int) * chunk_number)))
		return ;
	get_n_limits(q, g, chunk_number);	// get chunk_number chunks limits
	// aff("q", q, chunk_number);
	i = 0;
	while (i < chunk_number)
	{
		push_chunk(g, q[i], chunk_number);
		i++;
	}
	i = find_greatest(g->b);
	if (i)
	{
		if (i > ft_lstcount(g->b)  / 2)
			i -= ft_lstcount(g->b);
		straff_to(g, i, &rb, &rrb);
	}
	while (g->b)
		pa(g, 1);


	// g->v = 1;
	// display_lists(g);
	// aff("q", q, chunk_number);

	free(q);
}
