/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 20:22:21 by cbertola          #+#    #+#             */
/*   Updated: 2019/10/21 13:40:27 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *elem;
	t_list *head;

	if (!alst)
		return ;
	elem = *alst;
	head = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (elem->next)
			elem = elem->next;
		elem->next = new;
		*alst = head;
	}
	new->next = 0;
}
