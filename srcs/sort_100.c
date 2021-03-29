/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:23:46 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/29 12:30:09 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	push_3_lowest(t_game *g, int l1, int l2, int l3)
{
	int order[3];

	if (l1 > g->a_initial_size / 2)
		l1 -= g->a_initial_size;
	if (l2 > g->a_initial_size / 2)
		l2 -= g->a_initial_size;
	if (l3 > g->a_initial_size / 2)
		l3 -= g->a_initial_size;
}

void	sort_100(t_game *g)
{
	int	lowest[3];

	while (g->a)
	{
		lowest[0] = find_1st_lowest(g);
		lowest[1] = find_2nd_lowest(g, lowest[0]);
		lowest[2] = find_3rd_lowest(g, lowest[0], lowest[1]);
		printf("lowest -> [ %d | %d | %d ]\n", lowest[0], lowest[1], lowest[2]);


	}
}
