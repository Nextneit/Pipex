/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:38:46 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/08/20 11:47:25 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			counter;
	unsigned char	*str;

	str = (unsigned char *)b;
	counter = 0;
	while (counter < len)
	{
		str[counter] = (unsigned char)c;
		counter++;
	}
	return (b);
}
