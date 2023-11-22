/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:10:59 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/11/21 15:34:53 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(t_data *data, char **argv, int argc)
{
	data->fd = dup(STDERR_FILENO);
	data->file = open("here_doc.tmp", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	data->file2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (data->file == -1 || data->file2 == -1)
		msg_err("file2", data->flag_doc);
	while (1)
	{
		ft_printf("heredoc> ");
		data->line = get_next_line(data->fd);
		ft_putstr_fd(data->line, data->file);
		if (ft_strncmp(data->line, argv[2], ft_strlen(argv[2])) == 0)
		{
			close(data->fd);
			get_next_line(data->fd);
			break ;
		}
		free(data->line);
	}
	close(data->file);
	data->file = open("here_doc.tmp", O_RDONLY);
	if (data->file == -1)
		msg_err("file", data->flag_doc);
}
