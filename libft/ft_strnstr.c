/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamian <amamian@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:44:22 by amamian           #+#    #+#             */
/*   Updated: 2021/09/21 13:01:38 by amamian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*nstart;
	size_t		nlen;

	nlen = ft_strlen(needle);
	if (!nlen)
		return ((char *)haystack);
	nstart = haystack;
	while (true)
	{
		nstart = ft_strchr(nstart, *needle);
		if (nstart - haystack + nlen > len)
			return (NULL);
		if (!(ft_strncmp(nstart++, needle, nlen)))
			return ((char *)--nstart);
	}
}
