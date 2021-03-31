/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tester.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 08:26:04 by dait-atm          #+#    #+#             */
/*   Updated: 2021/03/31 07:18:59 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ps_tester.h"

void	new_rand_req(int *ar, int j, int *r)
{
	int	i;

	*r = rand() % 1000;	// MAXIMUM here
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

	i = -1;
	while (++i < size)
		printf("%d | %d\n", i, ar[i]);
}

char	**str_array_init(int *ar, int size)
{
	int		i;
	char	tmp[16];
	char	**s;

	s = malloc(sizeof(char *) * (size + 2)); // +1 for prog name
	s[0] = strdup("push_swap");
	i = 1;
	while (i - 1< size)
	{
		snprintf(tmp, 16, "%d ", ar[i - 1]);
		s[i] = strdup(tmp);
		i++;
	}
	s[i] = NULL;
	return (s);
}

int asprintf(char **strp, const char *fmt, ...);

char	*arg_str(int *ar, int size)
{
	int		i;
	char	*s;
	char	*tmp;

	s = strdup("./push_swap ");
	i = 0;
	while (i < size)
	{
		tmp = s;
		asprintf(&s, "%s%d ", s, ar[i]);
		//printf(">>> %s\n", s);
		free(tmp);
		i++;
	}
	return (s);
}

void	str_clear(char **as)
{
	//int	i;

	//i = 0;
	//while ((as)[i])
	//	free((as)[i++]);
	free(as[0]);
}

void	aff_string(char **as, int size)
{
	int i;

	i = 0;
	while (as[i])
		printf("[%s]\n", as[i++]);
}

int	exec_ps(char *as, char **env, int *cpt)
{
	char	l[16];
	FILE 	*r;
	FILE	*f;

	f = fopen("tmp.log", "w");
	r = popen(as, "r");
	while (fgets(l, 16, r))
	{
		(*cpt)++;
		//dprintf(2, "deb : %s", l);
		fprintf(f, "%s",l);
	}
	pclose(r);
	fclose(f);
	
	return (0);
}

int	exec_ch(char *as, char **env, int cpt)
{
	char	l[16];
	FILE 	*r;
	FILE	*f;

	int		sout[2];
	int		ret;

	strncpy(as + 2, "checker  ", 9);

	f = fopen("tmp.log", "r"); // need a test if exist

	pipe(sout);
	ret = dup(1);
	dup2(sout[1], 1);

	r = popen(as, "w");
	while (fgets(l, 16, f))
	{
		fprintf(r, "%s", l);
		//dprintf(2, "-> : %s", l);
	}
	pclose(r);
	fclose(f);

	read(sout[0], l, 16);
	//dup2(1, sout[1]);
	dup2(1, ret);
	close(ret);
	close(sout[0]);
	close(sout[1]);

	dprintf(2, "result : %s\b | %d\n", l, cpt);
	// traiter le retour OK KO Error
	if (strncmp(l, "OK\n", 3))
	{
		f = fopen("tmp.log", "a");
		fprintf(f, "\n\nerror found : \n%s\ncommand used : \n%s\n", l, as);
		fclose(f);
		dprintf(2, "Error or KO: see 'tmp.log' to find more inforamtions\n");
		return (1);
	}
	remove("tmp.log");
	return (0);
}

#define N 3

void	main(int argc, char **argv, char **env)
{
	int		size;
	int		*ar;
	char	*as[N];
	int		cpt[N];

	if (argc < 2)
		exit(1);
	srand(time (NULL));
	errno = 0;
	size = (int)strtoll(argv[1], NULL, 10);
	if (errno || size <= 0)
		exit(1);

	// loop N time and store the stats in cpt
	memset(cpt, 0, sizeof(int) * N);
	ar = init_array(size);
	//aff(ar, size);

	as[0] = arg_str(ar, size);
	as[1] = NULL;

	free(ar);
	//aff_string(as, size);

	exec_ps(as[0], env, &cpt[0]);

	exec_ch(as[0], env, cpt[0]);

	str_clear(as);
}
