/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 12:17:19 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/13 12:17:19 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "libft/includes/libft.h"
#include "get_next_line.h"

static int		get_next_scan(char **scan, char *buf)
{
	size_t	len;
	char	*start;
	char	*end;

	free(*scan);
	*scan = NULL;
	if (NULL == (start = ft_memcchr(buf, '\0', BUFF_SIZE)))
		return (-1);
	end = ft_memchr(buf, '\n', BUFF_SIZE);
	len = NULL == end ? BUFF_SIZE - (start - buf) : end - start;
	*scan = ft_strbuf(start, len);
	ft_memset(start, '\0', len + 1);
	return (NULL != end);
}

static char		*append_to_line(char **line, char *scan)
{
	char	*tmp;

	tmp = *line;
	*line = NULL == tmp ? ft_strdup(scan) : ft_strjoin(tmp, scan);
	free(tmp);
	return (*line);
}

int				get_next_line(const int fd, char **line)
{
	static char		buf[FD_MAX][BUFF_SIZE];
	char			*scan;
	int				scan_info;
	ssize_t			ret;

	if (BUFF_SIZE < 1 || fd < 0 || NULL == line)
		return (-1);
	*line = NULL;
	scan = NULL;
	while (1)
	{
		scan_info = get_next_scan(&scan, buf[fd]);
		if (scan_info == -1)
		{
			if ((ret = read(fd, buf[fd], BUFF_SIZE)) <= 0)
				break ;
			continue ;
		}
		append_to_line(line, scan);
		if (scan_info == 1)
			break ;
	}
	free(scan);
	return (1 == scan_info ? 1 : ret);
}
