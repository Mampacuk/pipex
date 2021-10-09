/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_processes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aisraely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:46:09 by aisraely          #+#    #+#             */
/*   Updated: 2021/10/09 20:46:10 by aisraely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				exit(0);
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
		returned = wait(NULL);
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
