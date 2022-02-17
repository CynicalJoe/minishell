#include "../include/minishell.h"

char *temp_file_gen(void)
{
	int i;
	char *name;

	i = 0;
	while(i <= INT_MAX)
	{
		name = itoa(i);
		if (!name)
			return (NULL);
		if (acces(name,F_OK) != 0)
			break;
		free(name);
		if (i == INT_MAX)
			return (NULL);
		i++;
	}
	return (name);
}

int read_write(int old_fd, int new_fd)
{
	char	*buf;
	int		ret;

	buf = malloc(sizeof(char));
	ret = 1;
	while (ret == 1)
	{
		ret = read(old_fd, buf, 1);
		write(new_fd, buf, 1);
	}
	if (ret < 0)
		return (-1);
	return (0);
}

int read_stdin(char *del, int new_fd)
{
	char *read;

	read = readline("");
	if (!read)
		return (-1);
	while(ft_strncmp(del, read, ft_strlen(del)) != 0)
	{
		write(new_fd, read, ft_strlen(read));
		free(read);
		read = readline("");
		if (!read)
			return (-1);
	}
	return (0);
}

int double_redir(int old_fd, char *del)
{
	int new_fd;
	char *name;

	name = temp_file_gen();
	if (!name)
		return(-1);
	new_fd = open(name, O_CREAT);
	if (read_write(old_fd, new_fd) == -1 || read_stdin(del, new_fd) == -1)
	{
		close(new_fd);
		if (unlink(name) == -1)
			return(-2);
		return(-1);
	}
	if (unlink(name) == -1)
		return (-2);
	return (new_fd);
}