/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:54:03 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/10 15:54:05 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	display_lists(t_game *g)
{
	t_stack	*a;
	t_stack	*b;

	a = g->a;
	b = g->b;
	system("clear");
	printf(" a  |  b\n");
	printf("---------\n");
	while (a || b)
	{
		if (a)
		{
			printf("%d", *((int *)a->content));
			a = a->next;
		}
		if (b)
		{
			printf("  |  %d", *((int *)b->content));
			b = b->next;
		}
		printf("\n");
	}
	usleep(300000);
}
