/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:58:13 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/12 12:55:17 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	get_pos(t_game *g, int pt)
{
	int		i;
	t_stack	*n;
	t_stack	*a;
	
	i = 0;
	n = ft_lstgetnb(g->a, pt);
	//printf("node : %d\n", *((int *)n->content));
	a = g->a;
	while (i < pt + 1)
	{
		if (*((int *)n->content) < *((int *)a->content))
		{
			//printf("..%d < %d\n", *((int *)n->content), *((int *)a->content));
			return (i);
		}
		i++;
		a = a->next;
	}
	return (pt);
}

void	ra_switch(t_game *g, int pt)
{
	int	endpoint;
	int	i;

	endpoint = get_pos(g, pt);
	//printf("pt : %d\n", pt);
									// pt = 5
	i = pt;
	while (i-- > 0) //
	{
		ra(g, 1);
	}
	pb(g, 1);
	//printf("endpoint : %d\n", endpoint);
	
	i = pt - endpoint;
	//printf("pt - ep: %d\n", pt - endpoint);
	while (i-- > 0)
	{
		rra(g, 1);
	}
	pa(g, 1);
	i = endpoint;
	while (i-- > 0)
	{
		rra(g, 1);
	}
}

void	insert_sort(t_game *g)
{
	t_stack	*a;
	t_stack	*p;
	int		pt;
	int		size;

	size = ft_lstcount(g->a);
	g->v = 1;
	//display_lists(g);
	//printf("size : %d\n", size);
	pt = 1;
	p = g->a;
	a = g->a->next;
	while (pt < size)
	{
		//printf("pt : %d\n", pt);
		//if (a->next && *((int *)a->content) > *((int *)a->next->content))
		if (a && *((int *)p->content) > *((int *)a->content))
		{
			//printf("[%d > %d]\n", *((int *)p->content), *((int *)a->content));
			ra_switch(g, pt);
			p = g->a;
			a = p->next;
			pt = 1;
		}
		//else
		//	printf("%d < %d\n", *((int *)p->content), *((int *)a->content));

		p = a;
		if (a->next)
			a = a->next;
		pt++;
		//display_lists(g);
	}
	//display_lists(g);
}

