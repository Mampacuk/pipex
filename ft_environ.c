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

/*
 * takes a declaration string, separates
 * the identifier before the first '='
 * and returns it. must be freed later
 */
char	*ft_separate_identifier(char *decl)
{
	int		i;
	char	*name;

	i = 0;
	while (decl[i] && decl[i] != '=')
		i++;
	name = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (decl[i] && decl[i] != '=')
	{
		name[i] = decl[i];
		i++;
	}
	return (name);
}

/*
 * goes through a string and checks whether
 * it's a valid identifier. returns 1 if it is,
 * 0 otherwise
 */
int	ft_isvalididentifier(const char *name)
{
	int	i;

	i = 0;
	if (!name)
		return (0);
	if (!(ft_isalpha(name[i]) || name[i] == '_') || name[i] == '=')
		return (0);
	i++;
	while (name[i])
	{
		if (!(ft_isalnum(name[i]) || name[i] == '_') || name[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_getenv_full(const char *name)
{
	int		i;
	int		name_len;
	char	*identifier;

	i = 0;
	identifier = ft_separate_identifier((char *) name);
	if (!ft_isvalididentifier(identifier))
	{
		free(identifier);
		return (NULL);
	}
	while (g_data.env->ptr[i])
	{
		name_len = ft_strlen(identifier);
		if (!ft_strncmp(g_data.env->ptr[i], identifier, name_len)
			&& (g_data.env->ptr[i][name_len] == '='
			|| g_data.env->ptr[i][name_len] == '\0'))
		{
			free(identifier);
			return (g_data.env->ptr[i]);
		}
		i++;
	}
	free(identifier);
	return (NULL);
}

char	*ft_getenv(const char *name)
{
	char	*env;

	env = ft_getenv_full(name);
	if (env)
		return (env + ft_strlen((char *) name) + 1);
	return (NULL);
}
