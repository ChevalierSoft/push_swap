/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dumb_sort_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:20:05 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/30 08:24:51 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	aff(int *d, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("d[%d] = %d\n", i, d[i]);
		i++;
	}
}


void	dumb_sort_100(t_game *g)
{
	int	q[N];

	get_n_limits(q, g);	// to split whe

	for (int i = 0; i < N; i++)
		printf("q[%d] = %d\n", i, q[i]);
}
