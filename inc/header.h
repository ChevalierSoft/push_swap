#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"

typedef struct s_stack
{
    t_list *s;
}               t_stack;

typedef struct s_game
{
    t_stack a;
    t_stack b;
}               t_game;

#endif