/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamian <amamian@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:15:13 by amamian           #+#    #+#             */
/*   Updated: 2021/09/21 13:06:34 by amamian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freearr(char **ret)
{
	size_t	i;

	i = 0;
	while (ret[i])
		free(ret[i++]);
	free(ret);
}

static size_t	ft_strcnt(char const *s, char c)
{
	size_t	ret;
	bool	flag;

	ret = 0;
	flag = true;
	while (s && *s)
	{
		if (*s == c)
			flag = true;
		else
		{
			if (flag)
				ret++;
			flag = false;
		}
		s++;
	}
	return (ret);
}

static const char	*ft_strnextdelim(const char **s, char c)
{
	const char	*end;

	end = *s;
	while (*end && *end == c)
		end++;
	if (!*end)
	{
		ft_putstr_fd("ft_strnextdelim !*end HERE\n", 1);
		return (NULL);
	}
	*s = end;
	while (*end && *end != c)
		end++;
	return (end);
}

char	**ft_split(char const *s, char c)
{
	size_t		cnt;
	char		**ret;
	const char	*end;
	size_t		i;

	cnt = ft_strcnt(s, c);
	if (!s)
		return (NULL);
	ret = ft_calloc(cnt + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	ret[cnt] = NULL;
	i = 0;
	while (i < cnt)
	{
		end = ft_strnextdelim(&s, c);
		ret[i] = ft_substr(s, 0, end - s);
		if (!ret[i++])
		{
			ft_freearr(ret);
			return (NULL);
		}
		s = end;
	}
	return (ret);
}
