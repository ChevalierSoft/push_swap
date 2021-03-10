/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 10:11:26 by dait-atm          #+#    #+#             */
/*   Updated: 2021/01/28 12:18:31 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_right(t_list *left, t_list *new_right)
{
	if (!left || !new_right)
		return ;
	new_right->next = left->next;
	left->next = new_right;
}
