#include "../inc/header.h"

static inline
int	find_first_pos_in_stack(t_stack **a, int n[2], int limit)
{
	int		i;

	n[0] = 0;
	i = 0;
	while (*a)
	{
		if (*((int *)(*a)->content) < limit)
		{
			n[0] = i;
			break ;
		}
		i++;
		*a = (*a)->next;
	}
	return (i);
}

static inline
void	find_last_pos_in_stack(t_stack **a, int n[2], int limit, int i)
{
	n[1] = n[0];
	while (*a)
	{
		if (*((int *)(*a)->content) < limit)
			n[1] = i;
		i++;
		*a = (*a)->next;
	}
}

int	find_first_chunk(t_game *g, int limit)
{
	t_stack	*a;
	int		n[2];
	int		i;

	a = g->a;
	i = find_first_pos_in_stack(&a, n, limit);
	find_last_pos_in_stack(&a, n, limit, i);
	if (n[0] > (g->a_size / 2))
		n[0] -= g->a_size;
	if (n[1] > (g->a_size / 2))
		n[1] -= g->a_size;
	if (ft_abs(n[0]) - ft_abs(n[1]) == 0)
	{
		if (n[0] >= 0)
			return (n[0]);
		else
			return (n[1]);
	}
	else if (ft_abs(n[0]) - ft_abs(n[1]) < 0)
		return (n[0]);
	else
		return (n[1]);
}
