/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tester.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 08:26:04 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/30 11:23:21 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ps_tester.h"

void	new_rand_req(int *ar, int j, int *r)
{
	int	i;

	*r = rand() % 1000;
	i = 0;
	while (i < j)
	{
		if (ar[i] == *r)
			new_rand_req(ar, j, r);
		i++;
	}
	return ;
}

int	new_rand(int *ar, int j)
{
	int	r;

	new_rand_req(ar, j, &r);
	return (r);
}

int	*init_array(int size)
{
	int	*ar;
	int	i;
	int	j;

	if (!(ar = malloc(sizeof(int) * size)))
		exit(0);
	j = 0;
	while (j < size)
	{
		ar[j] = new_rand(ar, j);
		j++;
	}
	return (ar);
}

void	aff(int *ar, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%d | %d\n", i, ar[i]);
		i++;
	}
}

char	*ar_to_str(int *ar, int size)
{
	int		i;
	char	*str;
	char	tmp[13];

	str = strdup("");
	i = 0;
	while (i < size)
	{
		sprintf(tmp, "%d ", ar[i]);
		strcat(str, tmp);
		i++;
	}
	return (str);
}

void	exec(char **av)
{
}

char	**str_array_init(int *ar, int size)
{
	int		i;
	char	tmp[16];
	char	**s;

	s = malloc(sizeof(char *) * size + 1);
	i = 0;
	while (i < size)
	{
		sprintf(tmp, "%d ", ar[i]);
		s[i] = strdup(tmp);
		i++;
	}
	s[i] = NULL;
}

void	str_clear(char ***as, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free((*as)[i]);
		i++;
	}
	free(as);
}

void	aff_string(char **as, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("[%s]\n", as[i]);
		i++;
	}
}

void	main(int argc, char **argv)
{
	int		size;
	int		*ar;
	char	**as;

	if (argc < 2)
		exit(1);
	srand(time (NULL));
	errno = 0;
	size = (int)strtoll(argv[1], NULL, 10);
	if (errno || size <= 0)
		exit(1);
	//printf("size : %d\n", size);

	ar = init_array(size);
	aff(ar, size);

	as = str_array_init(ar, size);
	write(1, "help\n", 5);
	aff_string(as, size);
	write(1, "help\n", 5);

	exec(as);

	str_clear(&as, size);
	free(ar);
}
