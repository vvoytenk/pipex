/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opokusyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 12:07:31 by opokusyn          #+#    #+#             */
/*   Updated: 2018/07/21 12:07:33 by opokusyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		inputfile(int fdpid, char *path, t_pip *p, char **env)
{
	int		fd;

	if ((fd = open(p->file1, O_RDONLY)) == -1)
		ft_panic("Can't read file.\n");
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(fdpid, STDOUT_FILENO);
	close(fdpid);
	if (execve(path, p->cmd1, env) == -1)
		ft_panic("ERROR: can't apply first command.\n");
	return (0);
}

int		sourcefile(int fdpid, char *path, t_pip *p, char **env)
{
	int		fd;

	if ((fd = open(p->file2, O_WRONLY)) == -1)
		ft_panic("Can't write into file.\n");
	dup2(fdpid, STDIN_FILENO);
	close(fdpid);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (execve(path, p->cmd2, env) == -1)
		ft_panic("ERROR: can't apply second command.\n");
	return (0);
}

int		pipex(t_pip *p, char **env)
{
	pid_t	pid;
	int		mypipefd[2];
	char	*curr;

	if (pipe(mypipefd))
		ft_panic("ERROR: can't create pipe.\n");
	pid = fork();
	if (pid == 0)
	{
		close(mypipefd[0]);
		if (!(curr = parse_path(p->path, p->cmd1[0])))
			ft_panic("ERROR: incorrect command.\n");
		inputfile(mypipefd[1], curr, p, env);
		free(curr);
	}
	else if (pid > 0)
	{
		close(mypipefd[1]);
		if (!(curr = parse_path(p->path, p->cmd2[0])))
			ft_panic("ERROR: incorrect command.\n");
		sourcefile(mypipefd[0], curr, p, env);
		free(curr);
	}
	return (0);
}

void	ft_panic(char *massage)
{
	ft_putstr_fd(massage, 2);
	exit(1);
}
