#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"

typedef t_list t_stack;

typedef struct s_game
{
	t_stack	*a;
	t_stack	*b;
	int		biggest;
	int		size;
}			t_game;

// display.c
void	display_lists(t_game *g);

#endif