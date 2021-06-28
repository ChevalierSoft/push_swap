/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:18:16 by dait-atm          #+#    #+#             */
/*   Updated: 2021/06/28 05:03:21 by dait-atm         ###   ########.fr       */
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
			if (*((int *)n->content) > *((int *)n->next->content))	// cmp
			{
				tmp = n->content;
				n->content = n->next->content;
				n->next->content = tmp;
				_sorted = 1;
			}
			n = n->next;
		}
		if (!_sorted)
			break ;
		m = m->next;
	}
}

void	fill_simpler_stack(t_game *g)
{
	t_stack	*d;			// dest
	t_stack	*sorted;	// copy

	t_stack	*n;			// on the copy d
	t_stack	*m;			// on the sorted list
	t_stack	*p;			// on a
	int		pos;

	d = ft_lstcpy(g->a, sizeof(int));
	sorted = ft_lstcpy(g->a, sizeof(int));
	ft_lstbubble_sort(sorted, ft_lstsize(g->a));

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
	fill_simpler_stack(g);
	return (0);
}
