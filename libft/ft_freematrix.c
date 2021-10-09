/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freematrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:50:57 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/09 20:50:58 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freematrix(char **matrix)
{
	int	i;

	i = ft_matrixlen(matrix) - 1;
	while (i >= 0)
		free((matrix)[i--]);
	free(matrix);
}
