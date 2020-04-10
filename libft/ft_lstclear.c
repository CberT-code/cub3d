/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 21:30:27 by cbertola          #+#    #+#             */
/*   Updated: 2019/10/21 13:42:41 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *elem;
	t_list *elem_del;

	if (!lst || !del)
		return ;
	elem = *lst;
	while (elem->next)
	{
		elem_del = elem;
		elem = elem->next;
		(*del)(elem_del);
	}
	(*del)(elem);
	*lst = NULL;
}
