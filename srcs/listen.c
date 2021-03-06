/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:11:08 by dait-atm          #+#    #+#             */
/*   Updated: 2021/07/09 04:51:00 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

static inline
void	wrong_input(t_game *g, char *l)
{
	free(l);
	quit(g, 1);
}

static inline
void	check_instruction(t_game *g, char *l)
{
	if (!ft_strncmp(l, "sa", 3))
		sa(g, 0);
	else if (!ft_strncmp(l, "sb", 3))
		sb(g, 0);
	else if (!ft_strncmp(l, "ss", 3))
		ss(g, 0);
	else if (!ft_strncmp(l, "pa", 3))
		pa(g, 0);
	else if (!ft_strncmp(l, "pb", 3))
		pb(g, 0);
	else if (!ft_strncmp(l, "ra", 3))
		ra(g, 0);
	else if (!ft_strncmp(l, "rb", 3))
		rb(g, 0);
	else if (!ft_strncmp(l, "rr", 3))
		rr(g, 0);
	else if (!ft_strncmp(l, "rra", 4))
		rra(g, 0);
	else if (!ft_strncmp(l, "rrb", 4))
		rrb(g, 0);
	else if (!ft_strncmp(l, "rrr", 4))
		rrr(g, 0);
	else
		wrong_input(g, l);
}

void	listen(t_game *g)
{
	char	*l;

	l = NULL;
	while (get_next_line(0, &l) > 0)
	{
		check_instruction(g, l);
		free(l);
		display_lists(g);
	}
	free(l);
}
