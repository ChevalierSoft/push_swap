/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_limits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 08:50:49 by dait-atm          #+#    #+#             */
/*   Updated: 2021/06/29 14:07:12 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

static
int	*stack_copy(t_stack *sk, int size)
{
	int	*d;
	int	i;

	d = malloc(sizeof(int) * size);
	if (!d)
		return (NULL);
	i = 0;
	while (i < size)
	{
		d[i] = *((int *)sk->content);
		sk = sk->next;
		i++;
	}
	return (d);
}

// 1 - copy a in an array d
// 2 - sort the array
// 3 - get N splits limits and free
void	get_n_limits(int *q, t_game *g, int chumk_number)
{
	int		*d;
	int		i;
	int		size;

	size = ft_lstcount(g->a);
	d = stack_copy(g->a, size);
	if (!d)
	{
		delete_game(g);
		exit(2);
	}
	ft_bubble_sort(d, size, &ft_cmp_int, &ft_swap_int);
	i = 0;
	while (i < chumk_number - 1)
	{
		q[i] = d[(size + (size * i)) / chumk_number];
		i++;
	}
	q[i] = d[size - 1];
	free(d);
}
