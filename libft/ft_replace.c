/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 14:21:44 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/03/26 12:35:46 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char       *ft_replace(char *str, char out, char in)
{
    int i;
    char *ptr;

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