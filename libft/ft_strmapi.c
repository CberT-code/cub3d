/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:44:25 by cbertola          #+#    #+#             */
/*   Updated: 2020/04/09 13:55:33 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int				u;
	unsigned int	i;
	char			*ptr;

	if (!(s))
		return (NULL);
	u = ft_strlen((char *)s);
	i = 0;
	if (!(ptr = malloc(u * sizeof(char) + 1)))
		return (NULL);
	while (*s)
	{
		ptr[i] = (*f)(i, *s++);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
