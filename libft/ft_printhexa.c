/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:36:19 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/08/20 11:47:47 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhexa(unsigned long long n, char c)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_printhexa(n / 16, c);
		if (count == -1)
			return (-1);
	}
	if (c == 'x')
	{
		count += ft_putchar("0123456789abcdef"[n % 16]);
		if (count == -1)
			return (-1);
	}
	else if (c == 'X')
	{
		count += ft_putchar("0123456789ABCDEF"[n % 16]);
		if (count == -1)
			return (-1);
	}
	return (count);
}
