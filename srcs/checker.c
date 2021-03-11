/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:18:16 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/11 12:26:38 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int main(int argc, char **argv)
{
	t_game	g;

	game_init(&g);
	if (check_args(&g, argc, argv))
		return (1);
	if (fill_stack(&g, argc, argv))
		return (1);
	if (g.v)
		display_lists(&g);
	listen(&g);
	if (is_sorted(&g))
		printf("OK\n");
	else
		printf("KO\n");
	delete_game(&g);
	return (0);
}
