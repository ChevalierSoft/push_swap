/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 14:11:18 by dait-atm          #+#    #+#             */
/*   Updated: 2021/06/14 11:57:27 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#include <limits.h>

static inline
void	prepare_ft_strtoll(int *neg, int *c, char **s, int *base)
{
	*neg = 0;
	while (*c == ' ')
	{
		*c = *(*s)++;
	}
	if (*c == '-')
	{
		*neg = 1;
		*c = *(*s)++;
	}
	else if (*c == '+')
		*c = **s++;
	if ((*base == 0 || *base == 16)
		&& *c == '0' && (**s == 'x' || **s == 'X'))
	{
		*c = ++*(*s)++;
		*base = 16;
	}
	if (*base == 0)
	{
		if (*c == '0')
			*base = 8;
		else
			*base = 10;
	}
}

static inline
void	prepare_strtoll(t_strtoll_content *cont, int neg, int base)
{
	if (neg)
		cont->cutoff = -(unsigned long long)LLONG_MIN;
	else
		cont->cutoff = (unsigned long long)LLONG_MAX;
	cont->cutlim = cont->cutoff % (unsigned long long)base;
	cont->cutoff /= (unsigned long long)base;
	cont->any = 0;
}

static inline
void	isll(const char *n, unsigned long long *a, char **s, int *c)
{
	*a = 0;
	*s = (char *)n;
	*c = (int)(**s);
	(*s)++;
}

static inline
int	ft_strtoll_loop(t_strtoll_content *cont, int base)
{
	if (ft_isdigit(cont->c))
		cont->c -= '0';
	else if (ft_isalpha(cont->c))
	{
		if (ft_isupper(cont->c))
			cont->c -= 'A' - 10;
		else
			cont->c -= 'a' - 10;
	}
	else
		return (0);
	if (cont->c >= base)
		return (0);
	if (cont->any < 0 || cont->acc > cont->cutoff
		|| (cont->acc == cont->cutoff && cont->c > cont->cutlim))
		cont->any = -1;
	else
	{
		cont->any = 1;
		cont->acc *= base;
		cont->acc += cont->c;
	}
	cont->c = *cont->s++;
	return (1);
}

long long	ft_strtoll(const char *nptr, char **endptr, int base)
{
	t_strtoll_content	cont;

	isll(nptr, &cont.acc, &cont.s, &cont.c);
	prepare_ft_strtoll(&cont.neg, &cont.c, &cont.s, &base);
	prepare_strtoll(&cont, cont.neg, base);
	while (ft_strtoll_loop(&cont, base))
		;
	if (cont.any < 0)
	{
		if (cont.neg)
			cont.acc = LLONG_MIN;
		else
			cont.acc = LLONG_MAX;
		errno = ERANGE;
	}
	else if (cont.neg)
		cont.acc = -cont.acc;
	if (endptr != NULL)
	{
		if (cont.any)
			*endptr = cont.s - 1;
		else
			*endptr = (char *)nptr;
	}
	return (cont.acc);
}
