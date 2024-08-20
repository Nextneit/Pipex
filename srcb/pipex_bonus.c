/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:38:32 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/08/20 12:30:35 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_pipex(t_data *data)
{
	data->file = 0;
	data->file2 = 0;
	data->i = 0;
	data->j = 0;
	data->env = NULL;
	data->cmd = NULL;
	data->path = NULL;
	data->tmp = NULL;
	data->tmp_path = NULL;
	data->flag_doc = 0;
	data->pid = 0;
}

int	split_env(char **env, t_data *data)
{
	while (ft_strncmp(*env, "PATH", 4) != 0)
		env++;
	*env += 5;
	data->env = split_quotes(*env, ':');
	if (data->env == NULL)
		return (free_all(data), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **env)
{
	t_data	*data;
	int		i;

	i = 0;
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	init_pipex(data);
	if (argc < chk_here_doc(data, argv[1]))
		return (free_all(data), ft_printf("Numero de argumentos invalido"));
	if (split_env(env, data) == 1)
		return (EXIT_FAILURE);
	if (get_commands(argc, argv, data) == 1)
		return (free_all(data), EXIT_FAILURE);
	if (chk_path(data, argc - 2) == 1)
		return (free_all(data), EXIT_FAILURE);
	exec_cmd(data, argv, argc);
	return (free_all(data), EXIT_SUCCESS);
}
