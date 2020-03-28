/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 20:32:10 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/03/28 14:29:54 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double			calc_dst_vector(t_vector vector, t_vector actual)
{
	double dst;

	dst = pow(vector.x - actual.x, 2) + pow(vector.y - actual.y, 2);
	return (dst);
}