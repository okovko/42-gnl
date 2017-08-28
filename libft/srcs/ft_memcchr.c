/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 01:03:51 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/28 04:14:59 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "libft.h"

void	*ft_memcchr(const void *mem, int c, size_t n)
{
	if (NULL == mem)
		return (NULL);
	while (n--)
		if (*(unsigned char *)mem++ != (unsigned char)c)
			return ((void *)(mem - 1));
	return (NULL);
}
