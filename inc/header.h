/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:54:12 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/12 10:09:55 by dait-atm         ###   ########.fr       */
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
	int		v;
	int		cpt;
}			t_game;

// check_args.c
int		check_args(t_game *g, int argc, char **argv);

// check_occ.c
int		check_occ(t_game *g, int tmp);

// delete_game.c
void 	delete_game(t_game *g);

// display.c
void	display_lists(t_game *g);

// dumb_sort.c
void	dumb_sort(t_game *g);

// fill_stack.c
int		fill_stack(t_game *g, int argc, char **argv);

// game_init.c
void	game_init(t_game *g);

// is_sorted.c
int		is_sorted(t_game *g);

// insert_sort.c
void	insert_sort(t_game *g);

// listen.c
void	listen(t_game *g);

// quit.c
void	quit(t_game *g, int err);

// sort_stack
void	sort_stack(t_game *g);

// operator's file
void	sa(t_game *g, int aff);
void	sb(t_game *g, int aff);
void	ss(t_game *g, int aff);
void	pa(t_game *g, int aff);
void	pb(t_game *g, int aff);
void	ra(t_game *g, int aff);
void	rb(t_game *g, int aff);
void	rr(t_game *g, int aff);
void	rra(t_game *g, int aff);
void	rrb(t_game *g, int aff);
void	rrr(t_game *g, int aff);

#endif
