#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"

typedef struct s_cmd
{
	char	**args;
	int		in;
	int		out;
}				t_cmd;

typedef struct s_env
{
	int		cmds;
	t_cmd	*commands;
	pid_t	*family;
	t_darr	*env;
	char	*here_doc;
}				t_env;

t_env	g_data;

/*
 * environment
 */
void	ft_inherit_environment(char **environ);
char	*ft_getenv(const char *name);
/*
 * parsing
 */
void	ft_get_arguments(char **argv, int argc);
void	ft_create_commands(char **argv, int argc);
void	ft_receive_heredoc(void);
/*
 * forking
 */
void	ft_fork_processes(void);
void	ft_block_main_process(void);
t_cmd	*ft_find_command(pid_t pid);
/*
 * executing
 */
void	ft_exec(t_cmd *cmd);

#endif
