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

// void	roll_to(t_game *g,int mid, int t2)
// {
// 	t_stack	*b;
// 	// int		t2;
	
// 	straff_to(g, t2, &rb, &rrb);
	
// }

void	straff_to_2(t_game *g, int loc_a, int loc_b) 
{ 
	int		i;
	void	(*f)(t_game *, int);

	if (!loc_a) 
		return ;
	i = ft_abs(loc_a);
	if (loc_a < 0)
		f = &rra; 
	else
		f = &ra;
	while (i--) 
		f(g, 1);
}

// sans opti : 786
// 1/2 opti  : 759
// opt       : 741

void	push_chunk(t_game *g, int *q, int l)
{
	t_stack	*a;
	int		t;
	int		j;
	t_item	lowest;
	t_item	greatest;
	t_stack	*n;
	int		t2;
	int		b_size;

	j = g->a_initial_size / N;
	a = g->a;
	// j = 6;	//deb
	while (j)
	{
		t = find_first_chunk(g, q[l]);
		// printf("t : %d\n", t);
		
		// printf("node : %d\n", *((int *)n->content));
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
			int		b_size;

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

			// straff_to_2(g, t, t2);
			// roll_to(g, *((int *)g->a->content), t2);
		}

		pb(g, 1);
		j--;

		// g->v = 1;
		// display_lists(g);
	}
}

void	dumb_sort_100(t_game *g)
{
	int	q[N];
	int	i;

	get_n_limits(q, g);	// get N chunks limits
	// aff("q", q, N);

	i = 0;
	// while (i < N)
	// {
		push_chunk(g, q, i);
		i++;
	// }
	// while (g->b)
	// 	pa(g, 1);
	g->v = 1;
	display_lists(g);
}
