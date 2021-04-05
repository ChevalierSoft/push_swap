/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:18:16 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/29 10:29:14 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	main(int argc, char **argv)
{
	t_game	g;

	game_init(&g, argc);
	if (check_args(&g, argc, argv))
		return (1);
	if (fill_stack(&g, argc, argv))
		return (1);
	g.a_size = ft_lstcount(g.a);
	g.a_initial_size = ft_lstcount(g.a);
	sort_stack(&g);
	delete_game(&g);
	return (0);
}
