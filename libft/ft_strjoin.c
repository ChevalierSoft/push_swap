/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:06:01 by dait-atm          #+#    #+#             */
/*   Updated: 2021/01/24 08:43:59 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	s1len;
	size_t	s2len;

	if (!s1 || !s2)
		return (0);
	s2len = ft_strlen(s2);
	s1len = ft_strlen(s1);
	s3 = malloc(sizeof(char) * (s1len + s2len + 1));
	if (!s3)
		return (0);
	ft_strncpy(s3, s1, s1len);
	ft_strncpy(s3 + s1len, s2, s2len);
	s3[s1len + s2len] = '\0';
	return (s3);
}

void	ft_strjoin2(char **s1, char const *s2)
{
	char	*new_s1;

	new_s1 = ft_strjoin((char const *)(*s1), s2);
	if (!new_s1)
		return ;
	free(*s1);
	*s1 = new_s1;
}

void	ft_strjoin3(char const *s1, char **s2)
{
	char	*new_s2;

	new_s2 = ft_strjoin(s1, (char const *)(*s2));
	if (!new_s2)
		return ;
	free(*s2);
	*s2 = new_s2;
}
