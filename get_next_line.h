/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 15:58:28 by olkovale          #+#    #+#             */
/*   Updated: 2017/09/07 19:55:45 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 256
# define BUFF_MAX 4096
# define FD_MAX 5000

# include "libft/incs/libft.h"

typedef struct		s_buf
{
	char			*dat;
	int				pos;
	int				uz;
	int				sz;
}					t_buf;

typedef struct		s_fdinfo
{
	int				fd;
	int				scan;
	t_lst			*ll;
	t_buf			buf;
}					t_fdinfo;

int					get_next_line(const int fd, char **line);

#endif
