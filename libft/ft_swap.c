/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:32:29 by dait-atm          #+#    #+#             */
/*   Updated: 2021/04/05 08:26:18 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_int(void *va, void *vb)
{
	int	*a;
	int	*b;
	int	c;

	a = (int *)va;
	b = (int *)vb;
	c = *a;
	*a = *b;
	*b = c;
}

void	ft_swap_float(float *a, float *b)
{
	float	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
