/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:38:32 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/11/23 10:28:17 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*void	ft_leaks(void)
{
	system("leaks -q pipex");
}*/

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
	if (argc != 5)
		return (ft_printf("Error: Numero de argumentos invalido"));
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	init_pipex(data);
	data->file = open(argv[1], O_RDONLY);
	data->file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->file == -1 || data->file2 == -1)
		return (close(data->file2), close(data->file2), free_all(data),
			EXIT_FAILURE);
	if (split_env(env, data) == 1)
		return (EXIT_FAILURE);
	if (get_commands(argc, argv, data) == 1)
		return (free_all(data), EXIT_FAILURE);
	if (chk_path(data, argc - 2) == 1)
		return (free_all(data), EXIT_FAILURE);
	exec_cmd(data);
	return (free_all(data), EXIT_SUCCESS);
}
