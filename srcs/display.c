/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:54:03 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/12 10:52:01 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

static inline
void	fill_panel(t_stack *sk, char *panel)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_itoa(*((int *)sk->content));
	while (i < ft_strlen(tmp))
	{
		panel[i] = tmp[i];
		i++;
	}
	free(tmp);
}

void	display_lists(t_game *g)
{
	unsigned char	panel[27];
	t_stack	*a;
	t_stack	*b;

	if (!g->v)
		return ;
	a = g->a;
	b = g->b;
	//system("clear");
	printf("operation n. %d\n", g->cpt);
	printf("     a      |      b\n");
	printf("—————————————————————————\n");
	while (a || b)
	{
		ft_memset(panel, ' ', 26);
		panel[26] = '\0';
		panel[12] = '|';
		if (a)
		{
			fill_panel(a, panel);
			a = a->next;
		}
		if (b)
		{
			fill_panel(b, panel + 13);
			b = b->next;
		}
		printf("%s\n", panel);
	}
	//usleep(300000);
}

