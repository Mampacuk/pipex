/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:19:25 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/09 20:48:13 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 * frees commands 
 */
void	ft_free_commands(void)
{
	int	i;

	i = 0;
	if (g_data.commands)
	{
		while (i < g_data.cmds)
		{
			if (g_data.commands[i].in != 0 && g_data.commands[i].in != 1)
				close(g_data.commands[i].in);
			if (g_data.commands[i].out != 1 && g_data.commands[i].out != 0)
				close(g_data.commands[i].out);
			if (g_data.commands[i].args)
				ft_freematrix(g_data.commands[i].args);
			i++;
		}
		free(g_data.commands);
		g_data.commands = NULL;
	}
	if (g_data.family)
	{
		free(g_data.family);
		g_data.family = NULL;
	}
}

int	main(int argc, char **argv, char **environ)
{
	if (argc < 4)
		ft_exit("Invalid number of arguments\n", 1);
	ft_inherit_environment(environ);
	g_data.cmds = argc - 3;
	if (!ft_strcmp("here_doc", argv[1]))
	{
		if (argc < 5)
			ft_exit("Invalid number of arguments\n", 1);
		g_data.here_doc = argv[2];
		g_data.cmds--;
	}
	ft_create_commands(argv, argc);
	ft_get_arguments(argv, argc);
	g_data.family = ft_calloc(g_data.cmds, sizeof(pid_t));
	ft_fork_processes();
	ft_block_main_process();
	ft_free_commands();
}
