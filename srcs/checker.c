/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:18:16 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/10 16:51:01 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int check_args(t_game *g, int argc, char **argv)
{
	int i;
	int	j;

	i = 1;
	if (argc < 2)
		return (1);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] == '+' || argv[i][j] == '-' || argv[i][j] == ' ')
			j++;
		if (!ft_strlen(argv[i] + j) || !ft_isaldigit(argv[i] + j))
			quit(g, 1);
		i++;
	}
	return (0);
}

int	check_occ(t_game *g, int tmp)
{
	t_stack	*a;

	a = g->a;
	while (a)
	{
		if (*((int *)a->content) == tmp)
			return (1);
		a = a->next;
	}
	return (0);
}

int	fill_stack(t_game *g, int argc, char **argv)
{
	t_list		*node;
	int			i;
	long long	tmp;
	int			*num;
	t_stack		*a;

	i = 1;
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
	display_lists(g);
	return (0);
}

int main(int argc, char **argv)
{
	t_game	g;

	g.a = NULL;
	g.b = NULL;
	if (check_args(&g, argc, argv))
		return (1);
	if (fill_stack(&g, argc, argv))
		return (1);

	listen(&g);

	delete_game(&g);
	return (0);
}
