/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darrerase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamian <amamian@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 17:43:21 by amamian           #+#    #+#             */
/*   Updated: 2021/09/22 17:15:01 by amamian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * iterate over the underlying array while freeing and skipping all `item`s (j)
 * and move the strings that are not equal to `item` to their corresponding
 * position (i)
 */
void	iter_items(t_darr *darr, char *item, size_t *i)
{
	size_t	j;

	j = 0;
	while (j < darr->len)
	{
		if (!ft_strcmp(darr->ptr[j], item))
		{
			while (j < darr->len && !ft_strcmp(darr->ptr[j], item))
			{
				free(darr->ptr[j]);
				darr->ptr[j] = NULL;
				j++;
			}
		}
		if (j >= darr->len)
			break ;
		darr->ptr[*i] = darr->ptr[j];
		j++;
		(*i)++;
	}
}

/*
 * erase an item from dynamic array
 * modifies `len` and leaves `cap` unchanged
 */
void	ft_darrerase(t_darr *darr, char *item)
{
	size_t	i;
	size_t	new_len;

	if (!darr || !item || !*item)
		return ;
	i = 0;
	iter_items(darr, item, &i);
	new_len = i;
	while (i < darr->len)
		darr->ptr[i++] = NULL;
	darr->len = new_len;
}
