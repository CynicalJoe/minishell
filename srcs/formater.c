#include "../include/minishell.h"

char	*remove_path(char **path)
{
	char	*new;
	size_t	len;

	len = ft_strlen(path[0]) - 4;
	new = malloc(sizeof(char) * len);
	if (!new)
		return (NULL);
	ft_strlcpy(new, &path[0][5], len);
	free(path[0]);
	path[0] = new;
	return (new);
}

char **get_path(char **env)
{
	int	i;
    char **path;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("PATH", env[i], 4))
			break ;
		i++;
	}
	//if (!env[i]) error condition
	path = ft_split(env[i], ':');
	path[0] = remove_path(path);
    //if condition for removepath sending NULL
    return (path);
}

char	*parse_path(char *path, char *cmd)
{
	char	*new;

	new = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(cmd) + 2));
	if (!new)
		return (NULL);
	ft_strlcpy(new, path, ft_strlen(path) + 1);
	ft_strlcat(new, "/", ft_strlen(new) + 2);
	ft_strlcat(new, cmd, ft_strlen(new) + ft_strlen(cmd) + 2);
	return (new);
}

char	*check_cmd_loc(char **path, char *cmd)
{
	int		fd;
	int		i;
	char	*new;

	i = 0;
	new = NULL;
	while (path[i])
	{
		if (new)
			free(new);
		new = parse_path(path[i], cmd);
		if (!new)
			return (NULL);
		fd = open(new, O_RDONLY);
		if (fd > 0)
		{
			close(fd);
			free(cmd);
			return (new);
		}
		close(fd);
		i++;
	}
	return (NULL);
}

