/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:38:38 by eclark            #+#    #+#             */
/*   Updated: 2022/08/18 15:25:40 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	window(t_data *f)
{
	int 	x;
	int		y;
	double	cr;
	double	ci;
	
	mlx_clear_window(f->mlx, f->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			cr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			ci = f->min_i + (double)y * (f->max_i - f->min_i) / HEIGHT;
			Mandelbrot(f, x, y, cr, ci);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

int main(int argc, char **argv)
{
	t_data f;
	f.kr = -0.766667;
	f.ki = -0.090000;
	f.min_r = -2.0;
	f.min_i = -1.5;
	f.max_r = 1.0;
	f.max_i = f.min_i + (f.max_r - f.min_r) * HEIGHT/WIDTH;

	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "test");
	f.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	f.data = (int *)mlx_get_data_addr(f.img, &f.bits_pp, &f.line_size, &f.endian);
	if (argc == 2)
		fractal_checker(ft_atoi(argv[1]), &f);
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_hook(f.win, 17, 0L, close_win, &f);
	mlx_hook(f.win, 2, 1L<<0, key_check, &f);
	mlx_loop(f.mlx);
}
