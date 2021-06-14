/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:25:44 by aisraely          #+#    #+#             */
/*   Updated: 2021/02/06 19:16:53 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	i;

	if (!s)
		return (NULL);
	if ((int)(start + len) > ft_strlen((char *)s))
		len = ft_strlen((char *)s) - start;
	result = (char *) malloc(sizeof(char) * (len + 1));
	if ((s != NULL && *s == '\0') || !(result))
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(result + i) = *(s + start + i);
		i++;
	}
	*(result + i) = '\0';
	return (result);
}
