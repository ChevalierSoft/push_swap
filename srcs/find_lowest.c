#include "../inc/header.h"

int	find_1st_lowest(t_game *g)
{
	t_stack	*sk;
	t_stack	*tmp;
	int		lowest;
	int		i;

	sk = g->a;
	tmp = g->a;
	lowest = 0;
	i = 0;
	while (sk)
	{
		if (*((int *)sk->content) < *((int *)tmp->content))
		{
			tmp = sk;
			lowest = i;
		}
		i++;
		sk = sk->next;
	}
	return (lowest);
}

int	find_2nd_lowest(t_game *g, int n)
{
	t_stack	*sk;
	t_stack	*tmp;
	int		lowest;
	int		i;

	tmp = g->a;
	i = 0;
	sk = g->a;
	if (n == 0)
	{
		i = 1;
		sk = g->a->next;
	}
	lowest = i;
	while (sk)
	{
		if (i != n && *((int *)sk->content) < *((int *)tmp->content))
		{
			tmp = sk;
			lowest = i;
		}
		i++;
		sk = sk->next;
	}
	return (lowest);
}
