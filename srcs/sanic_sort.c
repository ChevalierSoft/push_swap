/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 05:10:17 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/29 10:54:27 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	sanic_sort(t_game *g)
{
	if (g->argc < 2)
		return ;
	else if (g->argc == 2)
		sort_2(g);
	else if (g->argc <= 3)
		sort_3(g);
	else if (g->argc == 5)
		sort_5(g);
}
