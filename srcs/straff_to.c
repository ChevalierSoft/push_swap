/* ************************************************************************** */
/**/
/*::::::::::: */
/* straff_to.c:+::+::+: */
/*+:+ +:+ +:+ */
/* By: dait-atm <dait-atm@student.42.fr>+#++:+ +#+*/
/*+#+#+#+#+#+ +#+ */
/* Created: 2021/03/30 00:48:26 by dait-atm#+##+# */
/* Updated: 2021/03/30 00:48:26 by dait-atm ### ########.fr */
/**/
/* ************************************************************************** */

#include "../inc/header.h"

void	straff_to(t_game *g, int loc) 
{ 
	int		i;
	void	(*f)(t_game *, int);

	if (!loc) 
		return ;
	i = ft_abs(loc);
	if (loc < 0)
		f = &rra; 
	else
		f = &ra;
	while (i--) 
		f(g, 1);
}
