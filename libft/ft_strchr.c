/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:23:21 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/08/20 11:49:00 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if ((!*s && (char) c == '\0'))
		return ((char *) s);
	while (*s != '\0')
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
		if (*s == (char) c)
			return ((char *) s);
	}
	return (0);
}
