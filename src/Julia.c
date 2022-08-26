/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:14:30 by eclark            #+#    #+#             */
/*   Updated: 2022/08/26 14:43:46 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*include function for different values of ki and kr*/

void	julia(t_data *j, double zr, double zi)
{
	int		i;
	double	temp;

	i = -1;
	while (++i < MAX_ITERATIONS)
	{
		if (((zr * zr) + (zi * zi)) > 4.0)
		{
			break ;
		}
		temp = 2 * (zr * zi) + j->ki;
		zr = (zr * zr) - (zi * zi) + j->kr;
		zi = temp;
	}
	if (i == MAX_ITERATIONS)
		j->data[j->y * WIDTH + j->x] = 0;
	else
		j->data[j->y * WIDTH + j->x] = i * 80 + 15026768;
}
