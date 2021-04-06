/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 07:53:57 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/30 08:02:16 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	sort_4(t_game *g)
{
	int	low;

	low = find_1st_lowest(g);
	if (low > 2)
		low -= 4;
	straff_to(g, low, &ra, &rra);
	pb(g, 1);
	sort_3(g, g->a);
	g->v = 1;
	pa(g, 1);
	// display_lists(g);
}
