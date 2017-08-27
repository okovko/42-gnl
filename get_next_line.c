/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 12:17:19 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/27 01:05:01 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "libft/includes/libft.h"
#include "get_next_line.h"

static int		get_next_scan(char **scan, char *buf)
{
	size_t	len;
	char	*start;
	char	*end;

	*scan = NULL;
	if (NULL == (start = ft_memcchr(buf, '\0', BUFF_SIZE)))
		return (-1);
	end = ft_memchr(buf, '\n', BUFF_SIZE);
	len = NULL == end ? BUFF_SIZE - (start - buf) : end - start;
	*scan = ft_strbuf(start, len);
	ft_memset(start, '\0', len + 1);
	return (NULL != end);
}

static char		*get_line(t_list *lst, char **line)
{
	t_list	*head;
	int		sz;

	if (NULL == lst)
		return (NULL);
	sz = 1;
	head = lst;
	while (NULL != lst)
	{
		if (NULL != lst->content)
			sz += ft_strlen((char *)lst->content);
		lst = lst->next;
	}
	*line = malloc(sz);
	(*line)[sz - 1] = '\0';
	while (NULL != head)
	{
		*line = ft_strcat(*line, (char *)head->content);
		head = head->next;
	}
	return (*line);
}

static int		init_and_err(const int fd, char **line, char **scan)
{
	char	buf[1];

	if (BUFF_SIZE < 1 || NULL == line || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	*line = NULL;
	*scan = NULL;
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_fdlst	fdlst[FD_MAX];
	char			*buf;
	char			*scan;
	int				scan_info;
	ssize_t			ret;

	if (0 != init_and_err(fd, line, &scan))
		return (-1);
	buf = fdlst[fd].buf;
	while (true)
	{
		if (-1 == (scan_info = get_next_scan(&scan, buf)))
		{
			if ((ret = read(fd, buf, BUFF_SIZE)) <= 0)
				break ;
			continue ;
		}
		ft_lstadd(&fdlst[fd].lst, ft_lstnode((void *)scan, sizeof(char *)));
		if (1 == scan_info)
			break ;
	}
	*line = get_line(ft_lstsrev(&fdlst[fd].lst), line);
	ft_lstnfree(&fdlst[fd].lst, 1);
	return (ret != -1 && NULL != *line ? 1 : ret);
}
