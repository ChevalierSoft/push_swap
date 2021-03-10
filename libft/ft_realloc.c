/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <dait-atm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 20:16:25 by dait-atm          #+#    #+#             */
/*   Updated: 2020/12/08 22:49:49 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	unsigned char	*dest;
	size_t			len;
	size_t			slen;

	if (!ptr)
		return (malloc(size));
	if (!size && ptr)
	{
		free(ptr);
		return (NULL);
	}
	len = ft_strlen((char *)ptr);
	if (len < size)
		slen = len;
	else
		slen = size;
	dest = malloc(size);
	if (!dest)
		return (ptr);
	ft_memcpy(dest, ptr, slen);
	free(ptr);
	return (dest);
}
