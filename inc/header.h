/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:54:12 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/10 15:54:13 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include <errno.h>

typedef t_list t_stack;

typedef struct s_game
{
	t_stack	*a;
	t_stack	*b;
	int		biggest;
	int		size;
}			t_game;

// delete_game.c
void delete_game(t_game *g);

// display.c
void	display_lists(t_game *g);

#endif
