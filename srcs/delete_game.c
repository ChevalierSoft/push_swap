/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:36:29 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/29 10:26:09 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	delete_game(t_game *g)
{
	ft_lstclear(&g->a, &free);
	ft_lstclear(&g->b, &free);
}
