/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamian <amamian@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:44:22 by amamian           #+#    #+#             */
/*   Updated: 2021/09/21 13:03:09 by amamian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstinitsize;
	size_t	srcsize;

	srcsize = ft_strlen(src);
	dstinitsize = ft_strlen(dst);
	if (dstinitsize < dstsize)
	{
		if (srcsize < dstsize - dstinitsize)
			ft_memcpy(dst + dstinitsize, src, srcsize + 1);
		else
		{
			ft_memcpy(dst + dstinitsize, src, dstsize - dstinitsize - 1);
			dst[dstsize - 1] = '\0';
		}
		return (srcsize + dstinitsize);
	}
	return (srcsize + dstsize);
}
