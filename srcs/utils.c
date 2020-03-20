/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillebertola <cyrillebertola@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/20 20:32:10 by cyrillebert       #+#    #+#             */
/*   Updated: 2020/03/20 20:32:40 by cyrillebert      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double			calc_dst_vector(t_vector *vector, double actual_x, double actual_y)
{
	double dst;

	dst = pow(vector->x - actual_x, 2) + pow(vector->y - actual_y, 2);
	return (dst);
}