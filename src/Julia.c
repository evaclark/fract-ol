/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:14:30 by eclark            #+#    #+#             */
/*   Updated: 2022/08/18 12:59:22 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*include function for different values of ki and kr*/

void    Julia(t_data *var, int x, int y, double zr, double zi)
{
    int     i;
    double  temp;

    i = -1;
    while (++i < MAX_ITERATIONS)
    {
        if (((zr * zr) + (zi * zi)) > 4.0)
        {
            break ;
        }
        temp = 2 * (zr * zi) + var->ki;
        zr = (zr * zr) - (zi * zi) + var->kr;
        zi = temp;
    }
	if (i == MAX_ITERATIONS)
		var->data[y * WIDTH + x] = 0xDC2104;
	else
		var->data[y * WIDTH + x] = 0xFFFFFF;
}
