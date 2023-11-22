/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:08:10 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/11/22 14:52:14 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	msg_err(char *str, int here_doc)
{
	if (here_doc == 1)
		unlink("here_doc.tmp");
	perror(str);
	exit(EXIT_FAILURE);
}

void	free_all_2(t_data *data)
{
	int	i;

	i = 0;
	if (data->path != NULL)
	{
		while (data->path[i] != NULL)
			free(data->path[i++]);
		free(data->path);
	}
	if (data->flag_doc)
		unlink("here_doc.tmp");
	close(data->file);
	close(data->file2);
	if (data->line != NULL)
		free(data->line);
}

void	free_all(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (data->env != NULL)
	{
		while (data->env[i] != NULL)
			free(data->env[i++]);
		free(data->env);
	}
	i = -1;
	if (data->cmd != NULL)
	{
		while (data->cmd[++i] != NULL)
		{
			j = -1;
			while (data->cmd[i][++j] != NULL)
				free(data->cmd[i][j]);
			free(data->cmd[i]);
		}
		free(data->cmd);
	}
	free_all_2(data);
	free(data);
}

int	get_commands(int argc, char **argv, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 2;
	if (data->flag_doc != 0)
		j = 3;
	data->cmd = ft_calloc(argc - 2, sizeof(char **));
	if (!data->cmd)
		return (EXIT_FAILURE);
	while (i < argc - 2 && j < argc - 1)
	{
		data->cmd[i] = split_quotes(argv[j], ' ');
		if (!data->cmd[i])
			return (EXIT_FAILURE);
		i++;
		j++;
	}
	return (data->cmd[i] = NULL, EXIT_SUCCESS);
}

int	chk_path(t_data *d, int len)
{
	d->i = -1;
	d->path = ft_calloc(len, sizeof(char *));
	if (!d->path)
		return (EXIT_FAILURE);
	while (d->cmd[++d->i] != NULL)
	{
		d->j = -1;
		while (d->env[++d->j] != NULL)
		{
			d->tmp = ft_strjoin(d->env[d->j], "/");
			d->tmp_path = ft_strjoin(d->tmp, d->cmd[d->i][0]);
			if (!d->tmp_path || !d->tmp)
				return (EXIT_FAILURE);
			free(d->tmp);
			if (access(d->tmp_path, F_OK) == 0
				&& access(d->tmp_path, X_OK) == 0)
			{
				d->path[d->i] = d->tmp_path;
				d->tmp_path = NULL;
				break ;
			}
			free(d->tmp_path);
		}
	}
	return (d->path[d->i] = NULL, EXIT_SUCCESS);
}
