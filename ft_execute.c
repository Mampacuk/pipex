#include "pipex.h"

int	ft_error(char *name, char *desc)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(desc, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

void	ft_close_descriptors(void)
{
	int	i;

	i = 0;
	while (i < g_data.cmds)
	{
		if (g_data.commands[i].in != 0)
			close(g_data.commands[i].in);
		if (g_data.commands[i].out != 1)
			close(g_data.commands[i].out);
		i++;
	}
}

static void	ft_traverse_binaries(t_cmd *cmd)
{
	int		i;
	char	*newpath;
	char	**paths;

	execve(cmd->args[0], cmd->args, g_data.env->ptr);
	if (ft_getenv("PATH"))
	{
		paths = ft_split(ft_getenv("PATH"), ':');
		i = 0;
		while (paths[i])
		{
			newpath = ft_strjoin3(paths[i], "/", cmd->args[0]);
			execve(newpath, cmd->args, g_data.env->ptr);
			free(newpath);
			i++;
		}
		ft_freematrix(paths);
		ft_error(cmd->args[0], "command not found");
	}
	else
		ft_error(cmd->args[0], "No such file or directory");
}

void	ft_exec(t_cmd *cmd)
{
	if (dup2(cmd->in, 0) == -1 || dup2(cmd->out, 1) == -1)
		ft_exit(NULL, 1);
	ft_close_descriptors();
	if (cmd->args[0][0] == '/')
	{
		execve(cmd->args[0], cmd->args, g_data.env->ptr);
		ft_error(cmd->args[0], "No such file or directory");
	}
	else
		ft_traverse_binaries(cmd);
	exit(127);
}
