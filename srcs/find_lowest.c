/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lowest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:23:58 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/29 12:01:22 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

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

int	find_2nd_lowest(t_game *g, int n)
{
	t_stack	*sk;
	t_stack	*tmp;
	int		lowest;
	int		i;

	tmp = g->a;
	i = 0;
	sk = g->a;
	if (n == 0)
	{
		i = 1;
		sk = g->a->next;
	}
	lowest = i;
	while (sk)
	{
		if (i != n && *((int *)sk->content) < *((int *)tmp->content))
		{
			tmp = sk;
			lowest = i;
		}
		i++;
		sk = sk->next;
	}
	return (lowest);
}

int	find_3rd_lowest(t_game *g, int n, int m)
{
	t_stack	*sk;
	t_stack	*tmp;
	int		lowest;
	int		i;

	tmp = g->a;
	i = 0;
	sk = g->a;
	if (n == 0 || m == 0)
	{
		if (n == 1 || m == 1)
		{
			i = 2;
			sk = g->a->next->next;
		}
		else
		{
			i = 1;
			sk = g->a->next;
		}
	}
	lowest = i;
	while (sk)
	{
		if (i != n && i != m && *((int *)sk->content) < *((int *)tmp->content))
		{
			tmp = sk;
			lowest = i;
		}
		i++;
		sk = sk->next;
	}
	return (lowest);
}
