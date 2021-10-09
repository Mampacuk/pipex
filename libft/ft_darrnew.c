/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamian <amamian@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:54:21 by amamian           #+#    #+#             */
/*   Updated: 2021/09/26 17:00:48 by amamian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * initialize a new and empty dynamic array with a given capacity
 */
t_darr	*ft_darrnew(size_t cap)
{
	t_darr	*darr;
	char	**ptr;

	darr = ft_calloc(1, sizeof(t_darr));
	if (!darr)
		return (NULL);
	ptr = ft_calloc(cap, sizeof(char *));
	if (!ptr)
		return (NULL);
	darr->ptr = ptr;
	darr->len = 0;
	darr->cap = cap;
	return (darr);
}
