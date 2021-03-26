/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 06:22:52 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/26 09:18:40 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

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

