/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freematrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amamian <amamian@student.42yerevan.am>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:18:28 by aisraely          #+#    #+#             */
/*   Updated: 2021/08/16 18:58:45 by amamian          ###   ########.fr       */
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
