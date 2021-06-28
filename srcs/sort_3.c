/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 05:34:21 by dait-atm          #+#    #+#             */
/*   Updated: 2021/06/28 05:13:08 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	sort_3(t_game *g, t_stack *sk)
{
	int	a;
	int	b;
	int	c;

	a = *((int *)sk->content);
	b = *((int *)sk->next->content);
	c = *((int *)sk->next->next->content);
	if (a < b && b < c)
		return ;
	else if (a < c && c < b)
	{
		sa(g, 1);
		ra(g, 1);
	}
	else if (b < a && a < c)
		sa(g, 1);
	else if (b < c && c < a)
		ra(g, 1);
	else if (c < a && a < b)
		rra(g, a);
	else if (c < b && b < a)
	{
		sa(g, 1);
		rra(g, 1);
	}
}
