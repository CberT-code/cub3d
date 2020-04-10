/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:47:22 by cbertola          #+#    #+#             */
/*   Updated: 2020/04/09 13:55:13 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <libc.h>

static int		ft_find(char c, char const *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	long int	u;
	char		*ptr;
	long int	i;
	long int	j;

	if (!(s1 && set))
		return (0);
	u = ft_strlen((char *)s1);
	i = 0;
	while (ft_find(s1[i], set) == 1 && s1[i])
		i++;
	while (ft_find(s1[--u], set) == 1 && u > 0)
	{
	}
	j = u - i;
	if (j <= 0)
		ptr = ft_substr(s1, 0, 0);
	if (j > 0)
		ptr = ft_substr(s1, i, j + 1);
	return (ptr);
}
