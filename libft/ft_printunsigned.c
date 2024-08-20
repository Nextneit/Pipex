/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:34:52 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/08/20 11:52:56 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printunsigned(unsigned long long int n)
{
	int	count;
	int	aux;

	count = 0;
	if (n <= 9)
	{
		aux = ft_putchar(n + '0');
		if (aux == -1)
			return (-1);
		count += aux;
	}
	else
	{
		aux = ft_printunsigned (n / 10);
		if (aux == -1)
			return (-1);
		count += aux;
		aux = ft_printunsigned (n % 10);
		if (aux == -1)
			return (-1);
		count += aux;
	}
	return (count);
}
