#include "pipex.h"

void	ft_fork_processes(void)
{
	int	i;

	i = 0;
	while (i < g_data.cmds)
	{
		g_data.family[i] = fork();
		if (g_data.family[i] == 0)
		{
			if (!g_data.commands[i].args)
			{
				ft_putstr_fd("EMPTY ARGS!!!\n", 2);
				exit(0);
			}
			ft_exec(&g_data.commands[i]);
		}
		i++;
	}
}

void	ft_block_main_process(void)
{
	int		i;
	int		returned;
	t_cmd	*selected;

	i = 0;
	while (i < g_data.cmds)
	{
		printf("starting to wait...\n");
		returned = wait(NULL);
		printf("%d returned\n", returned);
		selected = ft_find_command(returned);
		if (selected)
		{
			if (selected->out != 1)
				close(selected->out);
			if (selected->in != 0)
				close(selected->in);
		}
		i++;
	}
}

t_cmd	*ft_find_command(pid_t pid)
{
	int	i;

	i = 0;
	while (i < g_data.cmds)
	{
		if (g_data.family[i] == pid)
			return (&g_data.commands[i]);
		i++;
	}
	return (NULL);
}
