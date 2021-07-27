/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:19:13 by aisraely          #+#    #+#             */
/*   Updated: 2021/07/10 13:19:14 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_pipex(int argc, char **argv)
{
	int		in;
	int		out;
	int		pipefd[2];
	pid_t	pid;

	in = open(argv[1], O_RDONLY);
	if (in == -1)
		ft_exit("Failed to open the input file.");
	out = open(argv[argc - 1], O_WRONLY);
	if (out == -1)
		ft_exit("Failed to open the output file.");
	if (pipe(pipefd) == -1)
		ft_exit("Failed to create a pipe.");
	pid = fork();
	if (pid == -1)
		ft_exit("Failed to fork the process.");
	if (pid == 0)
		ft_pipeout(pipefd, out, argv[3]);
	else
		ft_pipein(pipefd, in, argv[2]);
}

void	ft_pipein(int pipefd[2], int in, char *cmd1)
{
	char	**args;

	close(pipefd[0]);
	args = ft_split(cmd1, ' ');
	if (dup2(in, 0) == -1)
		ft_exit("Failed to connect infile with STDIN");
	if (dup2(pipefd[1], 1) == -1)
		ft_exit("Failed to connect STDOUT with pipe's WRITE END");
	if (args[0][0] == '/')
	{
		if (execve(args[0], args, environ) == -1)
			ft_exit("Invalid command address.");
	}
	else
		ft_exec(args[0], args);
	ft_freecharmatrix(args);
	close(in);
	close(pipefd[1]);
	wait(NULL);
}

void	ft_pipeout(int pipefd[2], int out, char *cmd2)
{
	char	**args;

	close(pipefd[1]);
	args = ft_split(cmd2, ' ');
	dup2(pipefd[0], 0);
	dup2(out, 1);
	if (args[0][0] == '/')
	{
		if (execve(args[0], args, environ) == -1)
			ft_exit("Invalid command address.");
	}
	else
		ft_exec(args[0], args);
	ft_freecharmatrix(args);
	close(out);
	close(pipefd[0]);
}

void	ft_exec(char *cmd, char **args)
{
	int		i;
	char	**paths;

	paths = NULL;
	i = 0;
	while (environ[i])
	{
		if (ft_strncmp(environ[i], "PATH", 4) == 0)
		{
			environ[i] += 5;
			paths = ft_split(environ[i], ':');
			break ;
		}
		i++;
	}
	ft_testpaths(cmd, args, paths);
}

void	ft_testpaths(char *cmd, char **args, char **paths)
{
	int		i;
	char	*temp;
	char	*newpath;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		newpath = ft_strjoin(temp, cmd);
		execve(newpath, args, environ);
		free(newpath);
		free(temp);
		i++;
	}
	ft_freecharmatrix(paths);
	ft_exit("No such command found.");
}
