/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 16:37:46 by olkovale          #+#    #+#             */
/*   Updated: 2017/08/28 04:14:46 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

t_list	*ft_lstnode(void const *content, size_t content_size)
{
	t_list	*node;

	if (NULL == (node = malloc(sizeof(t_list))))
		return (NULL);
	node->content = (void *)content;
	node->content_size = content_size;
	node->next = NULL;
	return (node);
}
