/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:27:59 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/08/20 11:47:41 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_filter(char const *content, int i, va_list *args)
{
	int	filter_print;

	filter_print = 0;
	if (content[i] == 'c')
		filter_print = ft_putchar(va_arg(*args, int));
	if (content[i] == 's')
		filter_print = ft_printstr(va_arg(*args, char *));
	if (content[i] == 'p')
		filter_print = ft_printptr(va_arg(*args, unsigned long long));
	if (content[i] == 'd' || content[i] == 'i')
		filter_print = ft_printdec(va_arg(*args, int));
	if (content[i] == 'u')
		filter_print = ft_printunsigned(va_arg(*args, unsigned int));
	if (content[i] == 'x' || content[i] == 'X')
		filter_print = ft_printhexa(va_arg(*args, unsigned int), content[i]);
	if (content[i] == '%')
		filter_print = ft_putchar('%');
	return (filter_print);
}

int	ft_printf(char const *content, ...)
{
	va_list	args;
	int		i;
	int		c;

	i = 0;
	c = 0;
	va_start(args, content);
	while (content[i])
	{
		if (content[i] != '%')
		{
			c += ft_putchar(content[i]);
			if (c == -1)
				return (-1);
		}
		else
		{
			i++;
			c += ft_filter(content, i, &args);
			if (c == -1)
				return (-1);
		}
		i++;
	}
	return (va_end(args), c);
}
