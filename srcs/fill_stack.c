/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:18:16 by dait-atm          #+#    #+#             */
/*   Updated: 2021/06/28 20:44:03 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

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

void	ft_lstbubble_sort(void *list)
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
			if ((*((int *)n->content) > *((int *)n->next->content)))
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

// fills sk[1] with number from 0 to stack_size int the order of sk[0]

void	fill_simpler_stack_loop(t_stack *sk[3], t_stack *pt[3])
{
	int		pos;

	pt[0] = sk[0];
	pt[1] = sk[1];
	while (pt[1])
	{
		pt[2] = sk[2];
		pos = 0;
		while (pt[2])
		{
			if (*((int *)pt[2]->content) == *((int *)pt[0]->content))
			{
				*((int *)pt[1]->content) = pos;
				break ;
			}
			++pos;
			pt[2] = pt[2]->next;
		}
		pt[0] = pt[0]->next;
		pt[1] = pt[1]->next;
	}
}

// sk[0] is g->a the stack as it came from the arguments
// sk[1] will be the stack used using numbers from 0 to stack_size
// sk[2] is a sorted version of sk[0]

void	fill_simpler_stack(t_game *g)
{
	t_stack	*sk[3];
	t_stack	*pt[3];

	sk[0] = g->a;
	sk[1] = ft_lstcpy(sk[0], sizeof(int));
	sk[2] = ft_lstcpy(sk[0], sizeof(int));
	ft_lstbubble_sort(sk[2]);
	fill_simpler_stack_loop(sk, pt);
	ft_lstclear(&sk[0], &free);
	ft_lstclear(&sk[2], &free);
	g->a = sk[1];
}

int	fill_stack(t_game *g, int argc, char **argv)
{
	t_list		*node;
	int			i;
	long long	tmp;
	int			*num;

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
