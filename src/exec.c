/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:40:39 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/11/20 15:38:25 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child(int *fd, t_data *data)
{
	close(fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		msg_err("Command dup2");
	if (dup2(data->file2, STDOUT_FILENO) == -1)
		msg_err("Command dup2");
	if (execve(data->path[1], data->cmd[1], NULL) == -1)
		msg_err("Command");
}

void	exec_cmd(t_data *data)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		msg_err("Pipe");
	pid = fork();
	if (pid == -1)
		msg_err("Fork");
	if (pid == 0)
		child(fd, data);
	else
	{
		close(fd[0]);
		if (dup2(data->file, STDIN_FILENO) == -1)
			msg_err("Command dup2");
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			msg_err("Command dup2");
		close(data->file);
		if (execve(data->path[0], data->cmd[0], NULL) == -1)
			msg_err("Command");
		waitpid(pid, NULL, 0);
	}
}
