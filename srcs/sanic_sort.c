/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 05:10:17 by dait-atm          #+#    #+#             */
/*   Updated: 2021/07/06 03:04:44 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	sanic_sort(t_game *g)
{
	if (is_sorted(g))
		return ;
	if (g->argc < 2)
		return ;
	else if (g->argc == 2)
		sort_2(g);
	else if (g->argc == 3)
		sort_3(g, g->a);
	else if (g->argc == 4)
		sort_4(g);
	else if (g->argc == 5)
		sort_5(g);
	else if (g->argc == 100)
		dumb_sort_100(g, 5);
	else if (g->argc == 500)
		dumb_sort_100(g, 10);
	else
		stupidous_totalus(g);
}
