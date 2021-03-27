/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 06:22:52 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/27 09:03:40 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"
/*
void 	sort_5(t_game *g)
{
	int i;

	i = 0;
	while (g->argc - i > 3)
	{
		pb(g, 1);
		i++;
	}
	if (g->argc == 5)
	{
		if (*((int *)g->b->content) > *((int *)g->b->next->content))
		{
			if (*((int *)g->a->content) < *((int *)g->a->next->next->content)
				&& *((int *)g->a->next->next->content) < *((int *)g->a->next->content))
			{
				ss(g, 1);
				ra(g, 1);
			}
			else if (*((int *)g->a->next->next->content) < *((int *)g->a->next->content)
				&& *((int *)g->a->next->content) < *((int *)g->a->content))
			{
				ss(g, 1);
				rra(g, 1);
			}
			else
			{
				sort_3(g);
				sb(g, 1);
			}
		}
		else
			sort_3(g);
	}
	else
		sort_3(g);
	i = 0;
	while (g->argc - i > 3)
	{
		pa(g, 1);
		if (*((int *)g->a->content) > *((int *)g->a->next->content))
			ra(g, 1);
		i++;
	}
}
*/

int	find_1st_lowest(t_game *g)
{
	t_stack	*sk;
	t_stack	*tmp;
	int		lowest;
	int		i;

	sk = g->a;
	tmp = g->a;
	lowest = 0;
	i = 0;
	while (sk)
	{
		if (*((int *)sk->content) < *((int *)tmp->content))
		{
			tmp = sk;
			lowest = i;
		}
		i++;
		sk = sk->next;
	}
	return (lowest);
}

void sort_5(t_game *g)
{
	int	low1;
	int low2;

	low1 = find_1st_lowest(g);
	printf("lowest : %d\n", low1);
	low2 = find_2nd_lowest(g);
	printf("lowest : %d\n", low2);

	// 1 - push both lowers to b, taking the fastest way
	// 2 - sort using sort_3 algo or make specific ss if g->b < g->b->next
	// pa pa
	
}

