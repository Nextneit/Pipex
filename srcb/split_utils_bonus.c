/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:38:22 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/08/20 12:30:54 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**split_quotes(char *env, char c)
{
	char	**arr;

	arr = split_loop(env, c);
	if (!arr)
		return (free_split_quotes(arr), NULL);
	return (arr);
}
