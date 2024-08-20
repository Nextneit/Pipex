/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:01:05 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/08/20 12:30:30 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	create_pipe(t_data *data)
{
	if (pipe(data->pipe_fd) == -1)
		msg_err("pipe", data->flag_doc);
	data->pid = fork();
}
