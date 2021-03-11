/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:24:48 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/11 12:26:18 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	game_init(t_game *g)
{
	g->a = NULL;
	g->b = NULL;
	g->v = 0;
	g->cpt = 0;
}
