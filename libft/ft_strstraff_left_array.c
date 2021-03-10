/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstraff_left_array.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 12:58:17 by dait-atm          #+#    #+#             */
/*   Updated: 2021/01/12 16:00:21 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_strstraff_left_array(char **a, int i)
{
	int	j;

	if (!a)
		return ;
	j = i + 1;
	if (a[i])
		free(a[i]);
	a[i++] = a[j++];
	while (a[i])
		a[i++] = a[j++];
}
