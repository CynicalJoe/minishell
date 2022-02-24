/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afulmini <afulmini@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:05:17 by afulmini          #+#    #+#             */
/*   Updated: 2022/02/24 12:48:30 by afulmini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*temp_file_gen(void)
{
	int i;
	char *name;

	i = 0;
	while(i <= INT_MAX)
	{
		name = ft_itoa(i);
		if (!name)
			return (NULL);
		if (access(name,F_OK) != 0)
			break;
		free(name);
		if (i == INT_MAX)
			return (NULL);
		i++;
	}
	return (name);
}

int	read_write(int old_fd, int new_fd)
{
	char	*buf;
	int		ret;

	if (old_fd == -1)
		return (0);
	buf = malloc(sizeof(char));
	ret = 1;
	while (ret == 1)
	{
		ret = read(old_fd, buf, 1);
		write(new_fd, buf, 1);
	}
	free(buf);
	if (ret < 0)
		return (-1);
	return (0);
}

int read_stdin(char *del, int new_fd)
{
	char *read;

	read = readline("$>");
	if (!read)
		return (-1);
	while(ft_strncmp(del, read, ft_strlen(del)) != 0)
	{
		write(new_fd, read, ft_strlen(read));
		free(read);
		read = readline("$>");
		if (!read)
			return (-1);
	}
	return (0);
}

int double_redir(t_redir fds, char *del)
{

	fds.temp_file = temp_file_gen();
	if (!fds.temp_file)
		return(-1);
	fds.fd_replaced = open(fds.temp_file, O_CREAT);
	if (read_write(fds.fd_backup, fds.fd_replaced) == -1 || read_stdin(del, fds.fd_backup) == -1)
	{
		close(fds.fd_replaced);
		if (unlink(fds.temp_file) == -1)
			return(-2);
		return(-1);
	}
	return (0);
}
