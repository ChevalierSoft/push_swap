/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 17:28:12 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/10 18:09:25 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	sa(t_game *g)
{
	void	*ref;

	if (!g->a || !g->a->next)
		return ;
	ref = g->a->content;
	g->a->content = g->a->next->content;
	g->a->next->content = ref;
}

