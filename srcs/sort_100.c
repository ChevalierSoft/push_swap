/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:23:46 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/30 08:10:01 by dait-atm         ###   ########.fr       */
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
			// ft_help();
			lil[0] = i;
			lil[1] = l[i];
		}
		i++;
	}
	printf("smallest -> %d : %d\n", lil[0], lil[1]);
	straff_to(g, lil[1]);
	pb(g, 1);
}

void	sort_3b(t_game *g)
{
	// too much rotations. maybe using rr and ss
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
