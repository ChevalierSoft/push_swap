/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:20:05 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/29 10:50:52 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void	sort_stack(t_game *g)
{
	//dumb_sort(g);
	// insert_sort(g);
	//dumb_sort2(g);
	sanic_sort(g);
}
