/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:49:23 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/08/20 11:48:00 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstr(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
	{
		count += ft_printstr("(null)");
		return (count);
	}
	while (str[i] != '\0')
	{
		count += ft_putchar(str[i]);
		if (count == -1)
			return (-1);
		i++;
	}
	return (count);
}
