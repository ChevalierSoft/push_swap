/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_occ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:18:16 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/11 09:11:41 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	check_occ(t_game *g, int tmp)
{
	t_stack	*a;

	a = g->a;
	while (a)
	{
		if (*((int *)a->content) == tmp)
			return (1);
		a = a->next;
	}
	return (0);
}

