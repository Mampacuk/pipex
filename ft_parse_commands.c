#include "pipex.h"

void	ft_receive_heredoc(void)
{
	char	*line;
	int		pipefd[2];
	
	pipe(pipefd);
	g_data.commands[0].in = pipefd[0];
	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		get_next_line(0, &line);
		if (!ft_strcmp(line, g_data.here_doc))
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, pipefd[1]);
		free(line);
	}
	close(pipefd[1]);
}

void	ft_create_commands(char **argv, int argc)
{
	int	i;
	int	pipefd[2];
	
	g_data.commands = ft_calloc(sizeof(t_cmd), g_data.cmds);
	if (!g_data.commands)
		ft_exit("Failed to allocate memory for commands.", 1);
	if (g_data.here_doc)
	{
		ft_receive_heredoc();
		printf("opening outfile: %s\n", argv[argc - 1]);
		g_data.commands[g_data.cmds - 1].out = open(argv[argc - 1],
			O_APPEND | O_WRONLY | O_CREAT, 0644);
	}
	else
	{
		printf("opening infile: %s\n", argv[1]);
		g_data.commands[0].in = open(argv[1], O_RDONLY, 0644);
		// printf("wrote\n");
		printf("opening outfile: %s\n", argv[argc - 1]);
		g_data.commands[g_data.cmds - 1].out = open(argv[argc - 1],
			O_TRUNC | O_WRONLY | O_CREAT, 0644);
		// printf("wrote\n");
	}
	printf("set first fd as %d and last fd as %d\n", g_data.commands[0].in, g_data.commands[g_data.cmds - 1].out);
	i = 1;
	while (i < g_data.cmds)
	{
		if (pipe(pipefd))
			ft_exit(NULL, 1);
		printf("pipe produced pipefd[0]:%d pipefd[1]:%d\n", pipefd[0], pipefd[1]);
		g_data.commands[i - 1].out = pipefd[1];
		g_data.commands[i].in = pipefd[0];
		i++;
	}
	i = 0;
	while (i < g_data.cmds)
	{
		printf("command[%d] has in:%d out:%d\n", i, g_data.commands[i].in, g_data.commands[i].out);
		if (g_data.commands[i].in == -1 || g_data.commands[i].out == -1)
			ft_exit(NULL, 1);
		i++;
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
	while (i < argc - 1)
		g_data.commands[j++].args = ft_split(argv[i++], ' ');
}
