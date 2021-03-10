/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:18:16 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/10 16:01:40 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int check_args(int argc, char **argv)
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
		{
			// ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("checker: error with the given argument(s).\n", 2);
			return (1);
		}
		i++;
	}
	ft_print("check_args done\n");
	return (0);
}

int	ret_error(t_game *g)
{
	ft_putstr_fd("Error\n", 2);
	ft_lstclear(&g->a, &free);
}

int	check_occ(t_game *g, int tmp)
{
	// will return 1 if there is occurences
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
	a = g->a;
	while (i < argc)
	{
		tmp = ft_strtoll(argv[i], NULL, 10);
		if (errno == ERANGE || tmp > INT32_MAX || tmp < INT32_MIN)
			return (ret_error(g));

		if (check_occ(g, (int)tmp))
			return (ret_error(g));
	
		num = malloc(sizeof(int));
		if (!num)
			return (ret_error(g));
		*num = (int)tmp;
		node = ft_lstnew(num);
		if (!node)
			return (ret_error(g));
		ft_lstadd_back(&g->a, node);
		display_lists(g);
		i++;
	}
	display_lists(g);
	printf("done\n");
	return (0);
}

int main(int argc, char **argv)
{
	t_game	g;

	if (check_args(argc, argv))
		return (1);

	if (fill_stack(&g, argc, argv))
		return (1);

	delete_game(&g);

	return (0);
}
