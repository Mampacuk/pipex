/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:15:24 by aisraely          #+#    #+#             */
/*   Updated: 2021/02/02 19:15:25 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (dest[k] != '\0' && k < size)
		k++;
	while (src[j] != '\0')
		j++;
	while (src[i] != '\0' && (i + k + 1 < size))
	{
		dest[i + k] = src[i];
		i++;
	}
	if (k < size)
		dest[i + k] = '\0';
	return (k + j);
}
