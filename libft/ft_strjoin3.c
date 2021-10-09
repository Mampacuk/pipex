/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamian <amamian@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:09:38 by amamian           #+#    #+#             */
/*   Updated: 2021/09/26 17:09:39 by amamian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin3(const char *s1, const char *s2, const char *s3)
{
	char	*temp;
	char	*ret;

	if (!s1 || !s2 || !s3)
		return (NULL);
	temp = ft_strjoin(s1, s2);
	if (!temp)
		return (NULL);
	ret = ft_strjoin(temp, s3);
	free(temp);
	return (ret);
}
