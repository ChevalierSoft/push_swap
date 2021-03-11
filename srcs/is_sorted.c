/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:18:16 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/11 10:44:21 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	is_sorted(t_game *g)
{
	t_stack	*a;

	if (g->b)
		return (0);
	a = g->a;	
	while (a->next)
	{
		if (*((int *)a->content) >= *((int *)a->next->content))
			return (0);
		a = a->next;
	}
	return (1);
}

