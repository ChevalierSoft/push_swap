/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:23:46 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/30 07:58:14 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	push_3_lowest(t_game *g, int *l, int n)
{
	int	i;
	int	lil[2];	// 0: id inside l[] | 1: position

	/// 1 - get the distances
	i = 0;
	g->a_size = ft_lstcount(g->a);
	while (i < n)
	{
		if (l[i] > g->a_size / 2)
		{
			l[i] -= g->a_size;
		}
		i++;
	}
	printf("lowest -> [ %d | %d | %d ]\n", l[0], l[1], l[2]);

	/// 2 - find the closest
	i = 1;
	lil[0] = 0;
	lil[1] = l[0];
	while (i < n)
	{
		if ((ft_abs(l[i]) == ft_abs(lil[1]) && l[i] > 0)
			|| ft_abs(l[i]) < ft_abs(lil[1]))
		{
			ft_help();
			lil[0] = i;
			lil[1] = l[i];
		}
		i++;
	}
	printf("smallest -> %d : %d\n", lil[0], lil[1]);
	straff_to(g, lil[1]);
	pb(g, 1);
	
	/// 3 - push_2_lowest with the 2 others.
	//l[0] = find_1st_lowest(g);
	//l[1] = find_2nd_lowest(g, l[0]);
	//push_2_lowest(g, l[0], l[1]);
}

// too much rotations. maybe using rr and ss
void	sort_3b(t_game *g)
{
	/*
	int	a;
	int	b;
	int	c;

	a = *((int *)g->b->content);
	b = *((int *)g->b->next->content);
	c = *((int *)g->b->next->next->content);
	if (a < b && b < c)             // a < b < c 
		return ;
	else if (a < c && c < b)        //a < c < b  
	{
		rb(g, 1);
		sb(g, 1);
		rrb(g, 1);
	}
	else if (b < a && a < c)        // b < a < c 
		sb(g, 1);
	else if (b < c && c < a)        // b < c < a 
		rb(g, 1);
	else if (c < a && a < b)        // c < a < b 
		rrb(g, a);
	else if (c < b && b < a)		// c < b < a 
	{
		sb(g, 1);
		rrb(g, 1);
	}
	*/
}

void	sort_100(t_game *g)
{
	int	lowest[3];

	//debug
	g->v = 1;

	//while (g->a)
	//{
		lowest[0] = find_1st_lowest(g);
		lowest[1] = find_2nd_lowest(g, lowest[0]);
		lowest[2] = find_3rd_lowest(g, lowest[0], lowest[1]);
		printf("lowest -> [ %d | %d | %d ]\n", lowest[0], lowest[1], lowest[2]);

		push_3_lowest(g, lowest, 3);

		printf("part 3:\n");
		display_lists(g);
		
		lowest[0] = find_1st_lowest(g);
		lowest[1] = find_2nd_lowest(g, lowest[0]);
		printf("lowest -> [ %d | %d ]\n", lowest[0], lowest[1]);
		
		push_2_lowest(g, lowest[0], lowest[1]);
		display_lists(g);

		sort_3b(g);
		display_lists(g);
	//}
}
