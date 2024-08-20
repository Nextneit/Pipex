/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:01:00 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/08/20 11:47:32 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printdec(long long int n)
{
	int		count;
	char	c;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		if (count == -1)
			return (-1);
		n = -n;
	}
	if (n > 9)
	{
		count += ft_printdec(n / 10);
		if (count == -1)
			return (-1);
	}
	c = n % 10 + '0';
	count += ft_putchar(c);
	if (count == -1)
		return (-1);
	return (count);
}
