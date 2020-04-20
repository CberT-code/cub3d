/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 14:21:44 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/04/20 16:36:58 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_replace(char *str, char out, char in)
{
	int		i;
	char	*ptr;

	if (!(ptr = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == out)
			ptr[i] = in;
		else
			ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
