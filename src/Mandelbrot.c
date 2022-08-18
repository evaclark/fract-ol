/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:33:33 by eclark            #+#    #+#             */
/*   Updated: 2022/08/18 15:07:47 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*equation for mandelbrot fractal set Zn+1 = Zn^2 + c where c is constant.
 * the Mandelbrot set is generated through iteration - with a constant given
 * z is the critical point 0 which increases by 1 each iteration. Zn must
 * remain bounded for all n > 0. */

void	Mandelbrot(t_data *f, int x, int y, double cr, double ci)
{
	int 	i;
	double	temp;
	double	zr;
	double	zi;

	i = -1;
	zr = 0;
	zi = 0;
	while (++i < MAX_ITERATIONS)
	{
		if (((zr * zr) + (zi * zi)) > 4.0)
		{
			break ;
		}
		temp = 2 * (zr * zi) + ci;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = temp;
	}
	if(i == MAX_ITERATIONS)
		f->data[y * WIDTH + x] = 0xFEFBD8;
	else if (i >= 20 && i < MAX_ITERATIONS)
		f->data[y * WIDTH + x] = 0x80CED6;
	else if (i >= 15 && i < 20)
		f->data[y * WIDTH + x] = 0x82B74B;
	else if (i >= 12 && i < 15)
		f->data[y * WIDTH + x] = 0xD6CBD3;
	else
		f->data[y * WIDTH + x] = 0x618685;
}
