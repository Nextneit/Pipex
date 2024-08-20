/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:14:14 by ncruz-ga          #+#    #+#             */
/*   Updated: 2024/08/20 11:45:50 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*actual;

	actual = *lst;
	if (!lst || !del)
		return ;
	while ((*lst))
	{
		del ((*lst)->content);
		actual = *lst;
		*lst = actual->next;
		free(actual);
	}
	lst = 0;
}
