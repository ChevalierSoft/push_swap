/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 02:24:06 by dait-atm          #+#    #+#             */
/*   Updated: 2020/12/31 17:44:33 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *nlst)
{
	if (!*alst)
	{
		*alst = nlst;
	}
	else
	{
		nlst->next = *alst;
		*alst = nlst;
	}
}
