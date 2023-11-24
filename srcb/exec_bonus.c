/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:40:39 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/11/24 12:08:18 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	chk_here_doc(t_data *data, char *argv)
{
	if (ft_strncmp(argv, "here_doc", 8) == 0)
		return (data->flag_doc = 1, 6);
	else
		return (5);
}

static void	check_f_doc(t_data *data, char **argv, int argc)
{
	if (data->flag_doc == 1)
		here_doc(data, argv, argc);
	else
	{
		data->file = open(argv[1], O_RDONLY);
		data->file2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (data->file == -1 || data->file2 == -1)
			msg_err("file", data->flag_doc);
	}
}

static void	child(int *fd, t_data *data)
{
	close(fd[0]);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		msg_err("Command dup2", data->flag_doc);
	if (execve(data->path[data->i], data->cmd[data->i], NULL) == -1)
		msg_err("Command", data->flag_doc);
}

static void	father(int *fd, pid_t pid, t_data *data)
{
	waitpid(pid, NULL, 0);
	close (fd[1]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		msg_err("fd[0]", data->flag_doc);
}

void	exec_cmd(t_data *data, char **argv, int argc)
{
	check_f_doc(data, argv, argc);
	if (dup2(data->file, STDIN_FILENO) == -1)
		msg_err("file", data->flag_doc);
	data->i = -1;
	while (data->cmd[++data->i] != NULL)
	{
		create_pipe(data);
		if (data->pid == -1)
			msg_err("fork", data->flag_doc);
		if (data->pid == 0)
		{
			if (data->cmd[data->i + 1] == NULL)
			{
				if (dup2(data->file2, STDOUT_FILENO) == -1)
					msg_err("file2", data->flag_doc);
				if (execve(data->path[data->i], data->cmd[data->i], NULL) == -1)
					msg_err("exec", data->flag_doc);
				break ;
			}
			child(data->pipe_fd, data);
		}
		else
			father(data->pipe_fd, data->pid, data);
	}
}
