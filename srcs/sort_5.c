/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 06:22:52 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/30 03:52:59 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

static inline
void	vec2d_int_init(int a[2], int i, int j)
{
	a[0] = i;
	a[1] = j;
}

void	push_2_lowest(t_game *g, int l1, int l2)
{
	int	order[2];

	/*if (l1 > 2)
		l1 -= 5;
	if (l2 > 2)
		l2 -= 5;*/
	if (l1 > g->a_size / 2)
		l1 -= g->a_size;
	if (l2 > (g->a_size ) / 2 + 1)
		l2 -= g->a_size;
	if (ft_abs(l1) - ft_abs(l2) == 0)
	{
		if (l1 > 0)
			vec2d_int_init(order, l1, l2);
		else
			vec2d_int_init(order, l2, l1);
	}
	else if (ft_abs(l1) - ft_abs(l2) < 0)
			vec2d_int_init(order, l1, l2);
	else
		vec2d_int_init(order, l2, l1);	
	straff_to(g, order[0]);
	pb(g, 1);
	order[1] = find_1st_lowest(g);
	if (order[1] > g->a_size)
		order[1] -= g->a_size;
	straff_to(g, order[1]);
	pb(g, 1);
}

static inline
void	sort_3_for_5(t_game *g)
{
	if (*((int *)g->b->content) < *((int *)g->b->next->content))
	{
		if (*((int *)g->a->content) < *((int *)g->a->next->next->content)
			&& *((int *)g->a->next->next->content) <
			*((int *)g->a->next->content))
		{
			ss(g, 1);
			ra(g, 1);
		}
		else if (*((int *)g->a->next->next->content) <
			*((int *)g->a->next->content)
			&& *((int *)g->a->next->content) < *((int *)g->a->content))
		{
			ss(g, 1);
			rra(g, 1);
		}
		else
		{
			sort_3(g, g->a);
			sb(g, 1);
		}
	}
	else
		sort_3(g, g->a);
}

void	sort_5(t_game *g)
{
	int	low1;
	int low2;

	/// debug
	// g->v = 1;

	g->a_size = 5;
	/// 1 - push both lowers to b, taking the fastest way
	low1 = find_1st_lowest(g);
	//printf("1st lowest : %d\n", low1);
	low2 = find_2nd_lowest(g, low1);
	//printf("2nd lowest : %d\n", low2);
	push_2_lowest(g, low1, low2);
	//display_lists(g);

	/// 2 - sort using sort_3 algo or make specific ss if g->b < g->b->next
	sort_3_for_5(g);	
	//display_lists(g);

	/// 3 - pa pa
	pa(g, 1);
	pa(g, 1);

	// display_lists(g);
}
