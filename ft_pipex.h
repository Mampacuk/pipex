#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "./libft/libft.h"

extern char	**environ;

void		ft_pipex(int argc, char **argv);
void		ft_pipein(int pipefd[2], int in, char *cmd1);
void		ft_pipeout(int pipefd[2], int out, char *cmd2);
void		ft_exec(char *cmd, char **args);
void		ft_testpaths(char *cmd, char **args, char **paths);

#endif