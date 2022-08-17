/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:33:33 by eclark            #+#    #+#             */
/*   Updated: 2022/08/17 14:38:43 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*equation for mandelbrot fractal set Zn+1 = Zn^2 + c where c is constant.
 * the Mandelbrot set is generated through iteration - with a constant given
 * z is the critical point 0 which increases by 1 each iteration. Zn must
 * remain bounded for all n > 0. */

void	Mandelbrot(t_data *f, int x, int y, double ci, double cr)
{
	int 	i;
	int		in_set;
	double	temp;
	double	zr;
	double	zi;

	i = -1;
	zr = 0;
	zi = 0;
	in_set = 1;
	while (++i < MAX_ITERATIONS)
	{
		if (((zr * zr) + (zi * zi)) > 4.0)
		{
			in_set = 0;
			break;
		}
		temp = 2 * (zr * zi) + ci;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = temp;
	}
	if(i == MAX_ITERATIONS)
		f->data[y * WIDTH + x] = 0x54FF82;
	else
		f->data[y * WIDTH + x] = 0xFFFFFF;
}

/*
void	draw_fractal(t_data *var)
{
	int		x;
	int		y;
	double	pr;
	double	pi;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = var->min_r + (double)x * (var->max_r - var->min_r) / WIDTH;
			pi = var->min_i + (double)y * (var->max_i - var->min_i) / HEIGHT;
			mandelbrot(var, x, y, pr, pi);
		}
	}
}

int main()
{
	t_data	m;
	m.min_r = -2.0;
	m.min_i = -1.5;
	m.max_r = 1.0;
	m.max_i = m.min_i + (m.max_r - m.min_r) * HEIGHT/WIDTH;

	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, WIDTH, HEIGHT, "Mandelbrot");
	draw_fractal(&m);
	mlx_loop(m.mlx);
}
*/
