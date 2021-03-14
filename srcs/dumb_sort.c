/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumb_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:20:05 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/11 12:34:31 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	dumb_sort(t_game *g)
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
}

void	find_lower(t_game *g, t_item *lower)
{
	t_stack	*a;
	int	pos;

	pos = 0;
	a = g->a;
	lower->p = 0;
	lower->v = *((int *)a->content);
	while (a)
	{
		if (*((int *)a->content) < lower->v)
		{
			lower->v = *((int *)a->content);
			lower->p = pos;
		}
		a = a->next;
		pos++;
	}
	// printf("lower : v = %d, p = %d\n", lower->v, lower->p);
}

void	find_greater(t_game *g, t_item *greater)
{
	t_stack	*a;
	int	pos;

	pos = 0;
	a = g->a;
	greater->p = 0;
	greater->v = *((int *)a->content);
	while (a)
	{
		if (*((int *)a->content) > greater->v)
		{
			greater->v = *((int *)a->content);
			greater->p = pos;
		}
		a = a->next;
		pos++;
	}
	// printf("greater : v = %d, p = %d\n", greater->v, greater->p);
}

void	find_lower_greater(t_game *g, t_item *lower, t_item *greater)
{
	t_stack	*a;
	int		pos;

	lower->p = 0;
	// lower->v = *((int *)a->content);
	greater->p = 0;
	// greater->v = *((int *)a->content);
	lower->v = INT32_MAX;
	greater->v = INT32_MIN;

	a = g->a;
	pos = 0;
	while (a)
	{
		// if (*((int *)a->content) <= lower->v)
		if (*((int *)a->content) < lower->v && *((int *)a->content) > g->mid)
		{
			lower->v = *((int *)a->content);
			lower->p = pos;
		}
		else if (*((int *)a->content) >= greater->v && *((int *)a->content) <= g->mid)
		{
			greater->v = *((int *)a->content);
			greater->p = pos;
		}
		a = a->next;
		pos++;
	}
	printf("lower : v = %d, p = %d\n", lower->v, lower->p);
	printf("greater : v = %d, p = %d\n", greater->v, greater->p);
}

void	get_closest(t_game *g, t_item *lo, t_item *gr, t_target *t)
{
	int	lo_dist;
	int	lo_neg;
	int	gr_dist;
	int	gr_neg;

	lo_neg = 1;
	gr_neg = 1;

	// get faster way to go to lower
	// printf("g->a_size : %d\n", g->a_size);
	// printf("g->a_size + 1 - lo->p = %d\n", g->a_size - lo->p);
	if (lo->p < g->a_size - lo->p)
		lo_dist = lo->p;
	else
	{
		lo_neg = -1;
		lo_dist = g->a_size - lo->p;
	}
	// get faster way to go to greater
	if (gr->p < g->a_size - gr->p)
		gr_dist = gr->p;
	else
	{
		gr_neg = -1;
		gr_dist = g->a_size - gr->p;
	}
	// get faster way between both
	// printf("(lo_dist < gr_dist) => (%d < %d)\n", lo_dist, gr_dist);
	if (lo_dist < gr_dist)
	{
		t->lg = 0;
		t->p = lo_dist * lo_neg;
	}
	else
	{
		t->lg = 1;
		t->p = gr_dist * gr_neg;
	}
	printf("target : lg = %d, p = %d\n", t->lg, t->p);
}

void	switcher_up_down(t_game *g, t_target *t)
{
	t_stack	*a;
	void	(*f)(t_game*, int);
	int		i;

	if (t->p > 0)
		f = &ra;
	else
		f = &rra;
	i = ft_abs(t->p);
	while (i--)
		f(g, 1);
	pb(g, 1);
	// printf("target : lg = %d, p = %d\n", t->lg, t->p);
	if (t->lg == 1)
	{
		rb(g, 1);
	}
	// if (g->a_initial_size - g->a_size == 0)
	// {
	// 	if (*((int *)g->b->content) > *((int *)g->b->next->content))
	// 	{
	// 		rb(g, 1);
	// 	}
	// }
}

static inline
void bubble_sort(int *list, int n)
{
	int	c;
	int	d;
	int	t;

	for (c = 0 ; c < n - 1; c++)
	{
		for (d = 0 ; d < n - c - 1; d++)
		{
			if (list[d] > list[d+1])
			{
				/* Swapping */
				t         = list[d];
				list[d]   = list[d+1];
				list[d+1] = t;
			}
		}
	}
}

int	lst_mid(t_stack	*sk, int sk_size)
{
	int		*sorted_array;
	t_stack	*tmp;
	int		i;
	int		res;

	sorted_array = malloc(sizeof(int) * sk_size);
	tmp = sk;
	i = 0;
	while (tmp)
	{
		sorted_array[i] = *((int *)tmp->content);
		tmp = tmp->next;
		i++;
	}
	bubble_sort(sorted_array, sk_size);
	res = sorted_array[sk_size / 2];
	free(sorted_array);
	printf("mid : %d\n", res);
	return (res);
}

void	dumb_sort2(t_game *g)
{
	t_stack		*a;
	t_item		lower; 		// lowest that is more than mid
	t_item		greater; 	// greatest that is less than mid
	t_target	t;
	int			pos;
	int			i;

	g->a_size = ft_lstcount(g->a);
	g->a_initial_size = g->a_size;

	g->mid = lst_mid(g->a, g->a_size);
g->v = 1;
		display_lists(g);
	while (g->a)
	{
		find_lower_greater(g, &lower, &greater);

		get_closest(g, &lower, &greater, &t);
		
		// push target into b
		switcher_up_down(g, &t);

		g->v = 1;
		display_lists(g);
		g->a_size--;
	}
	// while (g->b)
	// 	pa(g, 1);
}

