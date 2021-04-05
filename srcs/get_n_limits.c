#include "../inc/header.h"

static
int	*stack_copy(t_stack *sk, int size)
{
	int	*d;
	int	i;

	d = malloc(sizeof(int) * size);
	if (!d)
		return (NULL);
	i = 0;
	while (i < size)
	{
		d[i] = *((int *)sk->content);
		sk = sk->next;
		i++;
	}
	return (d);
}

void	get_n_limits(int q[N], t_game *g)
{
	int		*d;
	int		i;
	int		size;

	// 1 - copy a in an array d
	size = ft_lstcount(g->a);
	d = stack_copy(g->a, size);
	if (!d)
	{
		delete_game(g);
		exit(2);
	}
	
	// 2 - sort the array
	ft_bubble_sort(d, size, &ft_cmp_int,&ft_swap_int);

	// 3 - get N splits limits and free
	i = 0;
	while (i < N - 1)
	{
		q[i] = d[(size + (size * i))  / N];
		i++;
	}
	q[i] = d[size - 1];
	free(d);
}