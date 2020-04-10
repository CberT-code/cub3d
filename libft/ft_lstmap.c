/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:52:31 by cbertola          #+#    #+#             */
/*   Updated: 2019/10/24 15:26:17 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*one;

	if (!lst || !f)
		return (NULL);
	if (!(one = ft_lstnew(f(lst->content))))
		return (NULL);
	new = one;
	lst = lst->next;
	while (lst)
	{
		if (!(new->next = ft_lstnew(f(lst->content))))
		{
			del(new->next);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (one);
}
