/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 11:29:19 by olkovale          #+#    #+#             */
/*   Updated: 2017/06/21 17:11:43 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

char	*ft_strrchr(const char *str, char needle)
{
	char	c;
	char	*last;

	last = NULL;
	while ((c = *str))
	{
		if (c == needle)
			last = (char *)str;
		str++;
	}
	if (needle == '\0')
		return ((char *)str);
	return ((char *)last);
}
