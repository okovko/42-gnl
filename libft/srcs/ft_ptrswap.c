/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olkovale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 11:22:22 by olkovale          #+#    #+#             */
/*   Updated: 2017/07/20 06:55:22 by olkovale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ptrswap(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
