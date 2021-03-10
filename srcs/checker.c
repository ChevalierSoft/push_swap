#include "../inc/header.h"

int check_args(int argc, char **argv)
{
	int i;
	int	j;

	i = 1;
	if (argc < 2)
		return (1);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] == '+' || argv[i][j] == '-' || argv[i][j] == ' ')
			j++;
		if (!ft_strlen(argv[i + j]) || !ft_isaldigit(argv[i + j]))
		{
			// ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("checker: error with the given argument(s).\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ret_error(t_game *g)
{
	ft_putstr_fd("Error\n", 2);
	ft_lstclear(&g->a, &free);
}

int	fill_stack(t_game *g, int argc, char **argv)
{
	t_list		*node;
	int			i;
	long long	tmp;
	int			*num;

	i = 0;
	g->a = NULL;
	g->b = NULL;
	ft_help();
	while (i < argc)
	{
		tmp = ft_strtoll(argv[i], NULL, 10);
		// if (errno == ERANGE || tmp > INT32_MAX || tmp < INT32_MIN)
		if (!ft_strncmp(argv[i], "4", 2))
		{
			printf("la ");
			return (ret_error(g));
		}
		num = malloc(sizeof(int));
		// if (!num)
		// 	return (ret_error(g));
		*num = (int)tmp;
		node = ft_lstnew(num);
		// if (!n)
		// 	return (ret_error(g));
		ft_lstadd_back(&g->a, node);
		i++;
	}
	printf("done\n");
	display_lists(g);
	return (0);
}

int	check_occ(t_game *g)
{
	// will return 1 if there is occurences
	return (0);
}

int main(int argc, char **argv)
{
	t_game	g;

	if (check_args(argc, argv))
		return (1);

	if (fill_stack(&g, argc, argv))
		return (1);
	
	if (check_occ(&g))
		return (1);

	return (0);
}