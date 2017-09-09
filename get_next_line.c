/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 05:28:50 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/08 16:15:04 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "get_next_line.h"
#include "libft/incs/libft.h"

static int		process_buf(t_fdinfo *info)
{
	int		ret;
	char	*dat;

	dat = NULL;
	ret = get_next_buf(info->fd, BUFF_SIZE, &dat);
	info->buf.dat = dat;
	info->buf.sz = BUFF_SIZE;
	info->buf.pos = 0;
	info->buf.uz = ret;
	return (ret);
}

static int		process_lst(t_fdinfo *info)
{
	char	*ss;
	t_lst	*nod;

	while (true)
	{
		if (info->buf.pos >= info->buf.uz)
			process_buf(info);
		if (0 > info->buf.uz)
			return (-1);
		if (0 == info->buf.uz)
			return (0);
		info->scan = get_next_scan(info->buf.dat + info->buf.pos, "\n", &ss);
		if (NULL == (nod = ft_lstnode((void *)ss, info->scan)))
			return (-1);
		ft_lstadd(&info->ll, nod);
		info->buf.pos += info->scan + 1;
		if (0 > info->scan)
			return (-1);
		if (0 <= info->scan)
			return (1);
	}
}

static int		process_info(t_lst **ll, int fd, t_fdinfo **info)
{
	t_lst		*nod;
	char		*dat;
	int			ret;

	if (NULL != (nod = ft_lstmemfind(*ll, (void *)(int[]){fd},
						offsetof(t_fdinfo, fd), sizeof(fd))))
	{
		*info = nod->dat;
		return (1);
	}
	dat = NULL;
	if (0 >= (ret = get_next_buf(fd, BUFF_SIZE, &dat)))
		return (ret);
	*info = malloc(sizeof(**info));
	nod = ft_lstnode((void *)*info, sizeof(**info));
	if (NULL == *info || NULL == nod)
	{
		free(*info);
		free(nod);
		return (-1);
	}
	(*info)->fd = fd;
	(*info)->buf = (t_buf){.dat = dat, .sz = BUFF_SIZE, .uz = ret};
	ft_lstadd(ll, nod);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_lst	*ll = NULL;
	t_fdinfo		*info;
	int				ret;

	if (1 > BUFF_SIZE || !line || 0 > fd || 0 > read(fd, &(char[1]){0}, 0))
		return (-1);
	if (0 > (ret = process_info(&ll, fd, &info)))
		return (ret);
	ret = process_lst(info);
	info->ll = ft_lstsrev(&info->ll);
	*line = NULL;
	*line = ft_lststr(info->ll);
	ft_lstnfree(&info->ll, 1);
	if (0 >= ret)
		ft_lstdelcmp(&ll, info, ft_memcmp);
	return (ret);
}
