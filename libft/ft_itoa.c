/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:35:57 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/08/20 11:45:15 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	len = ft_nbrlen(n);
	str = (char *) malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	if (n == -2147483648)
		ft_strlcpy(str, "-2147483648", len +1);
	if (n == 0)
		ft_strlcpy(str, "0", len + 1);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[len--] = '\0';
	while (n > 0)
	{
		str[len] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (str);
}
