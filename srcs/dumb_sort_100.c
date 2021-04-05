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

void	ft_swap_int(void *va, void *vb)
{
	int	*a;
	int	*b;
	int c;

	a = (int *)va;
	b = (int *)vb;
	c = *a;
	*a = *b;
	*b = c;
}

int	ft_cmp_int(void *va, void *vb)
{
	return (*((int *)va) - *((int *)vb));
}

void	ft_bubble_sort2(void *list,
	int size,
	int (*cmp)(void *, void *),
	void (*swap)(void *, void *))
{
	int	c;
	int	d;
	int	t;

	for (c = 0; c < size - 1; c++)
	{
		for (d = 0; d < size - c - 1; d++)
		{
			if (cmp(&((int *)list)[d], &((int *)list)[d + 1]) > 0)
			{
				swap(&((int *)list)[d], &((int *)list)[d + 1]);
			}
		}
	}
}

void	get_quintils(int q[5], t_game *g)
{
	int		*d;
	t_stack *sk;

	// 1 - copy a in an array d
	d = stack_copy(g->a, ft_lstcount(g->a));
	if (!d)
	{
		delete_game(g);
		exit(2);
	}
	// aff(d, ft_lstcount(g->a));

	// 2 - sort the array

	// ft_bubble_sort(d, ft_lstcount(g->a), &ft_swap_int);
	ft_bubble_sort2(d, ft_lstcount(g->a), &ft_cmp_int,&ft_swap_int);
	// qsort(d, ft_lstcount(g->a), sizeof(int), &cmp_int);

	for (int i = 0; i < 100; i++)
		printf("d[%d] = %d\n", i, d[i]);

	// 3 - get 5 splits limits and free

	free(d);
}

void	dumb_sort_100(t_game *g)
{
	int	q[5];

	get_quintils(q, g);	// to split whe
}
