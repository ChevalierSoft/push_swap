/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 05:34:21 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/26 06:13:21 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	sort_3(t_game *g)
{
	int a;
	int b;
	int c;

	a = *((int *)g->a->content);
	b = *((int *)g->a->next->content);
	c = *((int *)g->a->next->next->content);
	if (a < b && b < c)				// a < b < c
	{
		printf("a < b < c\n");
		return ;
	}
	else if (a < c && c < b)		//a < c < b
	{
		printf("a < c < b\n");
		sa(g, 1);
		ra(g, 1);
	}
	else if (b < a && a < c)		// b < a < c
	{
		printf("b < a < c\n");
		sa(g, 1);
	}
	else if (b < c && c < a)		// b < c < a
	{
		printf("b < c < a\n");
		rra(g, 1);
	}
	else if (c < a && a < b)		// c < a < b
	{
		printf("c < a < b\n");
		ra(g, a);
	}
	else if (c < b && b < a)		// c < b < a
	{
		printf("c < b < a\n");
		sa(g, 1);
		rra(g, 1);
	}
}
