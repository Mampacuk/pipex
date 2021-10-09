#include "pipex.h"

void	ft_inherit_environment(char **environ)
{
	int	i;

	g_data.here_doc = NULL;
	g_data.env = ft_darrnew(ft_matrixlen(environ) + 1);
	i = 0;
	while (environ[i])
	{
		if (ft_strncmp(environ[i], "OLDPWD=", ft_strlen("OLDPWD=")))
			ft_darrpushback(g_data.env, ft_strdup(environ[i]));
		i++;
	}
}
