/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 15:58:28 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/28 05:44:59 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 256
# define FD_MAX 5000

# include "libft/incs/libft.h"

typedef struct		s_fdlst
{
	t_list			*lst;
	char			buf[BUFF_SIZE];
}					t_fdlst;

int					get_next_line(const int fd, char **line);

#endif
