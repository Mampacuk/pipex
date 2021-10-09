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
void	ft_inherit_environment(char **environ)
char	*ft_getenv_full(const char *name)
char	*ft_getenv(const char *name)
int		ft_isvalididentifier(const char *name)
char	*ft_separate_identifier(char *decl)

#endif
