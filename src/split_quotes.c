/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:00:28 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/11/16 14:12:58 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_countwords(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				if (s[i] == '\'' || s[i] == '\"')
				{
					i++;
					while (s[i] != '\'' && s[i] != '\"')
						i++;
				}
				i++;
			}
		}
		count++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			i++;
			len++;
			while (s[i] !='\'' && s[i] != '\"')
			{
				i++;
				len++;
			}
		}
		i++;
		len++;
	}
	return (len);
}

static void	ft_free(char **str, int str_ind)
{
	while (str_ind-- > 0)
		free(str[str_ind]);
	free(str);
}

char	**split_quotes(char *env, char c)
{
	char	**str;
	int		i;
	int		str_ind;

	i = 0;
	str_ind = -1;
	str = malloc(sizeof(char *) * (ft_countwords (env, c) + 1));
	if (!str)
		return (0);
	while (++str_ind < ft_countwords (env, c))
	{
		while (env[i] == c || env[i] == '\'' || env[i] == '\"')
			i++;
		str[str_ind] = ft_substr(env, i, ft_wordlen(env, c, i));
		if (!(str[str_ind]))
		{
			ft_free(str, str_ind);
			return (0);
		}
		i += ft_wordlen(env, c, i);
	}
	str[str_ind] = NULL;
	return (str);
}
