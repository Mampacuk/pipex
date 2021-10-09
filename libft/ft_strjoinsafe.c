/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinsafe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamian <amamian@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:09:34 by amamian           #+#    #+#             */
/*   Updated: 2021/09/26 17:09:35 by amamian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * same as ft_strjoin but also frees s1, s2 and sets them to NULL.
 * doesn't free anything if failed to allocate the joined string.
 */
char	*ft_strjoinsafe(char **s1, char **s2)
{
	char	*ret;

	if (!s1 || !s2 || !*s1 || !*s2)
		return (NULL);
	ret = ft_strjoin(*s1, *s2);
	if (!ret)
		return (NULL);
	free(*s1);
	free(*s2);
	*s1 = NULL;
	*s2 = NULL;
	return (ret);
}
