/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:19:25 by aisraely          #+#    #+#             */
/*   Updated: 2021/07/27 18:58:16 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	main(int argc, char **argv)
{
	if (argc < 5)
		ft_exit("To use, run: ./pipex file1 cmd1 cmd2 file2\n");
	ft_pipex(argc, argv);
}
