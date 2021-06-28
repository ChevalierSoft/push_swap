/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:18:16 by dait-atm          #+#    #+#             */
/*   Updated: 2021/06/28 04:39:51 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	ft_aff_list(t_stack *s)
{
	while (s)
	{
		printf("> %d\n", *((int *)s->content));
		s = s->next;
	}
}

t_list	*ft_lstcpy(t_list *src, int size)
{
	t_list			*dest;
	t_list			*n;
	unsigned char	*data;

	dest = NULL;
	while (src)
	{
		data = malloc(size);
		data = ft_memcpy(data, ((int *)src->content), size);		
		n = ft_lstnew(data);
		ft_lstadd_back(&dest, n);
		src = src->next;
	}
	return (dest);
}

void	ft_lstbubble_sort( \
	void *list, \
	int size \
	)
{
	t_list	*n;
	t_list	*m;
	void	*tmp;
	int		_sorted;

	_sorted = 0;
	m = list;
	while (m->next)
	{
		n = list;
		while (n->next)
		{
			// ft_help();
			if (*((int *)n->content) > *((int *)n->next->content))
			{
				// write(1, "swap\n", 5);
				tmp = n->content;//*((int *)n);
				// *((int *)n) = *((int *)n->next);
				// *((int *)n) = tmp;
				n->content = n->next->content;
				n->next->content = tmp;
				_sorted = 1;
			}
			n = n->next;
		}
		// write(1, "next\n", 5);
		// ft_aff_list(list);
		if (!_sorted)
			break ;
		m = m->next;
	}
}

void	fait_des_trucs(t_game *g)
{
	t_stack	*d;			// dest
	t_stack	*sorted;	// copy

	t_stack	*n;			// on the copy d
	t_stack	*m;			// on the sorted list
	t_stack	*p;			// on a
	int		pos;

	d = ft_lstcpy(g->a, sizeof(int));
	// d = ft_lstiter(g->a, ft_lstnew);

	sorted = ft_lstcpy(g->a, sizeof(int));
	// ft_lstiter(sorted, ft_lstnew);

	ft_lstbubble_sort(sorted, ft_lstsize(g->a));
	// ft_bubble_sort(&sorted, ft_lstsize(sorted), ft_cmp_int, ft_swap_int);

	n = d;
	p = g->a;
	while (n)
	{
		m = sorted;
		pos = 0;
		while (m)
		{
			if (*((int *)m->content) == *((int *)p->content))
			{
				*((int *)n->content) = pos;
				break ;
			}
				++pos;
			m = m->next;
		}
		p = p->next;
		n = n->next;
	}

	// ft_aff_list(d);
	ft_lstclear(&g->a, &free);
	g->a = d;
	ft_lstclear(&sorted, &free);

	// printf("\n");
	// ft_aff_list(sorted);
}

int	fill_stack(t_game *g, int argc, char **argv)
{
	t_list		*node;
	int			i;
	long long	tmp;
	int			*num;
	t_stack		*a;

	i = g->v;
	g->a = NULL;
	g->b = NULL;
	while (++i < argc)
	{
		tmp = ft_strtoll(argv[i], NULL, 10);
		if (errno == ERANGE || tmp > INT32_MAX || tmp < INT32_MIN
			|| check_occ(g, (int)tmp))
			quit(g, 1);
		num = malloc(sizeof(int));
		if (!num)
			quit(g, 1);
		*num = (int)tmp;
		node = ft_lstnew(num);
		if (!node)
			quit(g, 1);
		ft_lstadd_back(&g->a, node);
	}
	fait_des_trucs(g);
	return (0);
}
