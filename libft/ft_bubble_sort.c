/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 08:13:21 by dait-atm          #+#    #+#             */
/*   Updated: 2021/04/05 08:26:49 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bubble_sort( \
	void *list, \
	int size, \
	int (*cmp)(void *, void *), \
	void (*swap)(void *, void *))
{
	int	j;
	int	i;

	j = 0;
	while (j < size - 1)
	{
		i = 0;
		while (i < size - j - 1)
		{
			if (cmp(&((int *)list)[i], &((int *)list)[i + 1]) > 0)
				swap(&((int *)list)[i], &((int *)list)[i + 1]);
			i++;
		}
		j++;
	}
}
