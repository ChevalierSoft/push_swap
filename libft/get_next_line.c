/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 02:01:48 by dait-atm          #+#    #+#             */
/*   Updated: 2021/02/20 05:12:02 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

#ifdef __unix__
# ifndef FD_MAX
#  define FD_MAX FOPEN_MAX
# endif
#endif

#ifdef OS_Windows
# define FD_MAX FOPEN_MAX
#endif

#define ALERTE -1
#define RAS 619
#define FTN 69

static inline int	ret_a_plus(int *pt, int r)
{
	(*pt)++;
	return (r);
}

static inline int	ret_a_zero(int *pt, int r)
{
	(*pt) = 0;
	return (r);
}

static inline int	bosg(int *pt, char *buf, char **line, int res)
{
	char	mas[2];
	char	*tmp;

	mas[1] = '\0';
	while (*pt < res)
	{
		if (buf[*pt] == '\n')
			return (ret_a_plus(pt, 1));
		else
		{
			tmp = (*line);
			mas[0] = buf[(*pt)++];
			if (!((*line) = ft_strjoin(tmp, mas)))
			{
				free(tmp);
				return (ALERTE);
			}
			free(tmp);
		}
	}
	if (res != BUFFER_SIZE)
		return (ret_a_zero(pt, 0));
	return (RAS);
}

static int			get_next_line_proxy(t_gnldata *d, char **l, int *ok, int fd)
{
	if (d->a[fd] > 0 && d->a[fd] < BUFFER_SIZE && d->buf[fd][d->a[fd]])
	{
		if (d->res[fd] < BUFFER_SIZE)
			return (bosg(&(d->a[fd]), d->buf[fd], l, d->res[fd]));
		*ok = bosg(&(d->a[fd]), d->buf[fd], l, d->res[fd]);
		if (*ok != RAS)
			return (*ok);
	}
	return (FTN);
}

int					get_next_line(int fd, char **line)
{
	static t_gnldata	d;
	int					is_ok;
	int					ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1 || read(fd, d.buf[fd], 0) < 0)
		return (-1);
	(*line) = ft_strdup("");
	ret = get_next_line_proxy(&d, line, &is_ok, fd);
	if (ret != FTN)
		return (ret);
	d.res[fd] = read(fd, d.buf[fd], BUFFER_SIZE);
	while (d.res[fd])
	{
		d.a[fd] = 0;
		if (d.res[fd] < BUFFER_SIZE)
			return (bosg(&(d.a[fd]), d.buf[fd], (line), d.res[fd]));
		is_ok = bosg(&(d.a[fd]), d.buf[fd], line, BUFFER_SIZE);
		if (is_ok != RAS)
			return (is_ok);
		ft_memset(d.buf, 0, BUFFER_SIZE);
		d.res[fd] = read(fd, d.buf[fd], BUFFER_SIZE);
	}
	return (0);
}
