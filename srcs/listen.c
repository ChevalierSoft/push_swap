/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:11:08 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/11 11:15:00 by dait-atm         ###   ########.fr       */
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
		sa(g);
	else if (!ft_strncmp(l, "sb", 3))
		sb(g);
	else if (!ft_strncmp(l, "ss", 3))
		ss(g);
	else if (!ft_strncmp(l, "pa", 3))
		pa(g);
	else if (!ft_strncmp(l, "pb", 3))
		pb(g);
	else if (!ft_strncmp(l, "ra", 3))
		ra(g);
	else if (!ft_strncmp(l, "rb", 3))
		rb(g);
	else if (!ft_strncmp(l, "rr", 3))
		rr(g);
	else if (!ft_strncmp(l, "rra", 4))
		rra(g);
	else if (!ft_strncmp(l, "rrb", 4))
		rrb(g);
	else if (!ft_strncmp(l, "rrr", 4))
		rrr(g);
	else
		wrong_input(g, l);
}

void	listen(t_game *g)
{
	char	*l;

	while (get_next_line(0, &l) >= 1)
	{
		//printf("%s\n", l);
		check_instruction(g, l);
		free(l);
		display_lists(g);
	}
	printf("_ %s\n", l);
	if (*l != '\0')
	{
		free(l);
		quit(g, 1);	
	}
	//display_lists(g);
	free(l);
}

