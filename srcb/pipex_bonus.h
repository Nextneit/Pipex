/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:32:08 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/11/22 14:43:39 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data
{
	int		file;
	int		file2;
	char	**env;
	char	***cmd;
	char	*tmp_path;
	char	**path;
	int		i;
	int		j;
	char	*tmp;
	int		flag_doc;
	char	*line;
	int		fd;
}				t_data;

int		split_env(char **env, t_data *data);
char	**split_quotes(char *env, char c);
void	init_pipex(t_data *data);
void	msg_err(char *str, int here_doc);
void	free_all(t_data *data);
int		get_commands(int argc, char **argv, t_data *data);
int		chk_path(t_data *d, int len);
void	exec_cmd(t_data *data, char **argv, int argc);
int		chk_here_doc(t_data *data, char *argv);
void	here_doc(t_data *data, char **argv, int argc);
char	**split_loop(char *s, char d);
void	free_split_quotes(char **arr);

#endif
