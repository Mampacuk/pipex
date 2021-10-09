/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:19:25 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/09 16:53:06 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_receive_heredoc(void)
{
	char	*line;
	int		pipefd[2];
	
	pipe(pipefd);
	g_data.commands[0].in = pipefd[0];
	while (1)
	{
		get_next_line(0, &line);
		if (!ft_strcmp(line, g_data.here_doc))
		{
			free(line);
			break ;
		}
		ft_putstr_fd(pipefd[1], line);
		free(line);
	}
}

void	ft_parse_commands(char **argv, int argc)
{
	int	i;
	int	pipefd[2];
	
	if (g_data.here_doc)
	{
		ft_receive_heredoc();
		g_data.commands[g_data.cmds - 1].out = open(argv[argc - 1],
			O_APPEND | O_WRONLY | O_CREAT);
	}
	else
	{
		g_data.commands[0].in = open(argv[1], O_RDONLY, 0644);
		if (g_data.commands[0].in == -1)
		{
			perror("pipex");
			ft_exit(NULL, 1);
		}
		g_data.commands[g_data.cmds - 1].out = open(argv[argc - 1],
			O_TRUNC | O_WRONLY | O_CREAT);
	}
	g_data.commands = ft_calloc(sizeof(t_cmd), g_data.cmds);
	i = 1;
	while (i < g_data.cmds)
	{
		pipe(pipefd);
		g_data.commands[i - 1].out = pipefd[1];
		g_data.commands[i].in = pipefd[0];
	}
}

void	ft_get_arguments(char **argv, int argc)
{
	int	i;
	int	j;

	i = 2;
	if (g_data.here_doc)
		i++;
	j = 0;
	while (i < argc - 2)
		g_data.commands[j++].args = ft_split(argv[i++], ' ');
}

int	main(int argc, char **argv, char **environ)
{
	if (argc < 4)
		ft_exit("Invalid number of arguments\n", 1);
	ft_inherit_environment(environ);
	g_data.cmds = argc - 3;
	if (!ft_strcmp("here_doc"), argv[1]))
	{
		if (argc < 5)
			ft_exit("Invalid number of arguments\n", 1);
		g_data.here_doc = argv[2];
		g_data.cmds--;
	}
	ft_create_commands(argv, argc);
	ft_get_arguments(argv, argc);
}
