/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:18:16 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/11 11:07:37 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	fill_stack(t_game *g, int argc, char **argv)
{
	t_list		*node;
	int			i;
	long long	tmp;
	int			*num;
	t_stack		*a;

	i = 1 + g->v;
	g->a = NULL;
	g->b = NULL;
	while (i < argc)
	{
		tmp = ft_strtoll(argv[i], NULL, 10);
		if (errno == ERANGE || tmp > INT32_MAX || tmp < INT32_MIN)
			quit(g, 1);

		if (check_occ(g, (int)tmp))
			quit(g, 1);
	
		num = malloc(sizeof(int));
		if (!num)
			quit(g, 1);
		*num = (int)tmp;
		node = ft_lstnew(num);
		if (!node)
			quit(g, 1);
		ft_lstadd_back(&g->a, node);
		i++;
	}
	return (0);
}

