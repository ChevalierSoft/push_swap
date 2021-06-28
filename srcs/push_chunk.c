#include "../inc/header.h"

static inline
void	greatest_lowest_item(t_stack *sk, t_item *greatest, t_item *lowest)
{
	int	i;

	i = 0;
	greatest->p = i;
	greatest->v = *((int *)sk->content);
	lowest->p = i;
	lowest->v = greatest->v;
	while (sk)
	{
		if (*((int *)sk->content) > greatest->v)
		{
			greatest->v = *((int *)sk->content);
			greatest->p = i;
		}
		else if (*((int *)sk->content) < lowest->v)
		{
			lowest->v = *((int *)sk->content);
			lowest->p = i;
		}
		i++;
		sk = sk->next;
	}
}

static inline
int	roll_lowest_greatest(t_game *g, t_item *lowest, t_item *greatest, int t)
{
	t_stack	*b;
	int		pos;

	greatest_lowest_item(g->b, greatest, lowest);
	if (t > greatest->v)
		return (greatest->p);
	else if (t < lowest->v)
		return (greatest->p);
	b = g->b;
	pos = 0;
	while (b)
	{
		if (*((int *)b->content) > lowest->v && *((int *)b->content) < t)
		{
			lowest->v = *((int *)b->content);
			lowest->p = pos;
		}
		b = b->next;
		pos++;
	}
	return (lowest->p);
}


void	push_chunk(t_game *g, int limit, int chunk_number)
{
	int		t;
	int		j;
	t_item	lowest;
	t_item	greatest;
	t_stack	*n;
	int		t2;
	int		b_size;

	j = g->a_initial_size / chunk_number;
	while (j && g->a)
	{
		t = find_first_chunk(g, limit);
		if (g->b)
		{
			if (t < 0)
			{
				t += g->a_size;
				n = ft_lstgetnb(g->a, t);
				t -= g->a_size;
			}
			else
				n = ft_lstgetnb(g->a, t);
			t2 = roll_lowest_greatest(g, &lowest, &greatest, *((int *)n->content));
			b_size = ft_lstcount(g->b);
			if (t2 > b_size / 2)
				t2 -= b_size;
			while (t < 0 && t2 < 0)
			{
				rrr(g, 1);
				t++;
				t2++;
			}
			while (t > 0 && t2 > 0)
			{
				rr(g, 1);
				t--;
				t2--;
			}
			straff_to(g, t, &ra, &rra);
			straff_to(g, t2, &rb, &rrb);
		}
		else
			straff_to(g, t, &ra, &rra);
		pb(g, 1);
		j--;
	}
}
