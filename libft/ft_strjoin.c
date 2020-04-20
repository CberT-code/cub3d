/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbertola <cbertola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:27:36 by cbertola          #+#    #+#             */
/*   Updated: 2020/04/20 16:36:15 by cbertola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ptr;
	long int	u;
	long int	v;
	long int	i;

	if (!(s1 && s2))
		return (NULL);
	u = ft_strlen((char *)s1);
	v = ft_strlen((char *)s2);
	i = -1;
	if (!(ptr = malloc((u + v) * (sizeof(char) + 1))))
		return (NULL);
	while (*s1)
		ptr[++i] = (char)*s1++;
	while (*s2)
		ptr[++i] = (char)*s2++;
	ptr[++i] = '\0';
	return (ptr);
}
