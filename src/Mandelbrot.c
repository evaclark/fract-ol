/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:33:33 by eclark            #+#    #+#             */
/*   Updated: 2022/08/04 17:19:03 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*equation for mandelbrot fractal set Zn+1 = Zn^2 + c where c is constant.
 * the Mandelbrot set is generated through iteration - with a constant given
 * z is the critical point 0 which increases by 1 each iteration. Zn must
 * remain bounded for all n > 0. */

void	mandelbrot(t_data *var, int x, int y, double ci, double cr)
{
	int 	i;
	int		in_set;
	double	temp;

	i = -1;
	var->zr = 0;
	var->zi = 0;
	in_set = 1;
	while (++i < MAX_ITERATIONS)
	{
		if ((var->zr * var->zr + var->zi * var->zi) > 4.0)
		{
			in_set = 0;
			break;
		}
		temp = 2 * var->zr * var->zi + ci;
		var->zr = var->zr * var->zr - var->zi * var->zi + cr;
		var->zi = temp;
	}
	if (in_set == 1)
		my_mlx_pixel_put(var, y, x, 0xFFA500);
}

void	draw_fractal(t_data *var)
{
	int		x;
	int		y;
	double	cr;
	double	ci;

	y = -1;
	while (++y < 1000)
	{
		x = -1;
		while (++x < 1000)
		{
			cr = var->min_r + (double)x * (var->max_r - var->min_r) / WIDTH;
			ci = var->min_i + (double)y * (var->max_i - var->min_i) / HEIGHT;
			mandelbrot(var, x, y, cr, ci);
		}
	}
}
