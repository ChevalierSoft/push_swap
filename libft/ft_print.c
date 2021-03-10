/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 01:40:07 by dait-atm          #+#    #+#             */
/*   Updated: 2021/01/07 17:32:15 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_print_endl(void *s)
{
	ft_print(s);
	ft_print("\n");
}

void	ft_printr(char *s)
{
	ft_print(MAG);
	ft_print(s);
	ft_print(RST);
}

void	ft_help(void)
{
	ft_printr("help\n");
}
