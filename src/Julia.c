/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:14:30 by eclark            #+#    #+#             */
/*   Updated: 2022/08/26 01:18:27 by eclark           ###   ########.fr       */
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
    /*
	if (i == MAX_ITERATIONS)
		var->data[y * WIDTH + x] = 0xAC1917;
	else if (i >= MAX_ITERATIONS / 2 && i < MAX_ITERATIONS)
		var->data[y * WIDTH + x] = 0xD70E17;
	else if (i >= MAX_ITERATIONS / 3 && i < MAX_ITERATIONS / 2)
		var->data[y * WIDTH + x] = 0xE54A50;
	else if (i >= MAX_ITERATIONS / 4 && i < MAX_ITERATIONS / 3)
		var->data[y * WIDTH + x] = 0xE46828;
    else if (i >= MAX_ITERATIONS / 4.5 && i < MAX_ITERATIONS / 4)
        var->data[y * WIDTH + x] = 0xC0982B;
    else if (i >= MAX_ITERATIONS / 5 && i < MAX_ITERATIONS / 4.5)
        var->data[y * WIDTH + x] = 0xF0B319;
    else if (i >= MAX_ITERATIONS / 5.5 && i < MAX_ITERATIONS / 5)
        var->data[y * WIDTH + x] = 0xEEC76B;
    else if (i >= MAX_ITERATIONS / 6 && i < MAX_ITERATIONS / 5.5)
        var->data[y * WIDTH + x] = 0x768B45;
    else if (i >= MAX_ITERATIONS / 6.5 && i < MAX_ITERATIONS / 6)
        var->data[y * WIDTH + x] = 0x93AE55;
    else
    */
        var->data[y * WIDTH + x] = i == MAX_ITERATIONS ? 0 : i * 80 + 15026768;

}
