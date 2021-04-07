/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:18:16 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/29 09:51:29 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int	check_args(t_game *g, int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 2)
		return (1);
	if (!ft_strncmp(argv[1], "-v", 3))
	{
		if (argc < 3)
			return (1);
		g->v = i++;
		// g->argc--;
	}
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] == '+' || argv[i][j] == '-' || argv[i][j] == ' ')
			j++;
		if (!ft_strlen(argv[i] + j) || !ft_isaldigit(argv[i] + j))
			quit(g, 1);
		i++;
	}
	return (0);
}
