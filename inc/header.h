/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:54:12 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/10 17:38:42 by dait-atm         ###   ########.fr       */
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

// listen.c
void	listen(t_game *g);

// quit.c
void	quit(t_game *g, int err);

// operator's file
void	sa(t_game *g);
void	sb(t_game *g);
void	ss(t_game *g);
void	pa(t_game *g);
void	pb(t_game *g);
void	ra(t_game *g);
void	rb(t_game *g);
void	rr(t_game *g);
void	rra(t_game *g);
void	rrb(t_game *g);
void	rrr(t_game *g);

#endif
