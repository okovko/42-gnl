/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbuf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 13:40:41 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/28 04:15:11 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

char	*ft_strbuf(const char *buf, size_t sz)
{
	char	*str;

	if (NULL == buf)
		return (NULL);
	if (NULL == (str = ft_strnew(sz)))
		return (NULL);
	return (ft_strncpy(str, buf, sz));
}
