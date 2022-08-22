/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:18:09 by eclark            #+#    #+#             */
/*   Updated: 2022/08/22 10:44:01 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(int n)
{
	t_data	j;

	j.n = n;
	j.kr = -0.7;
	j.ki = 0.27015;
	j.max_r = 2.0;
	j.min_r = -2.0;
	j.min_i = -2.0;
	j.max_i = j.min_i + (j.max_r - j.min_r) * HEIGHT/WIDTH;

	j.mlx = mlx_init();
	j.win = mlx_new_window(j.mlx, WIDTH, HEIGHT, "Julia");
	j.img = mlx_new_image(j.mlx, WIDTH, HEIGHT);
	j.data = (int *)mlx_get_data_addr(j.img, &j.bits_pp, &j.line_size, &j.endian);
	draw(&j, n);
	mlx_mouse_hook(j.win, mouse_hook, &j);
	mlx_hook(j.win, 17, 0L, close_win, &j);
	mlx_hook(j.win, 2, 1l<<0, key_check, &j);
	mlx_loop(j.mlx);
}

void	init_mandel(int n)
{
	t_data	m;
	
	m.n = n;
	m.max_r = 1.0;
	m.min_r = -2.0;
	m.min_i = -1.5;
	m.max_i = m.min_i + (m.max_r - m.min_r) * HEIGHT/WIDTH;

	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, WIDTH, HEIGHT, "Mandelbrot");
	m.img = mlx_new_image(m.mlx, WIDTH, HEIGHT);
	m.data = (int *)mlx_get_data_addr(m.img, &m.bits_pp, &m.line_size, &m.endian);
	draw(&m, n);
	mlx_mouse_hook(m.win, mouse_hook, &m);
	mlx_hook(m.win, 17, 0L, close_win, &m);
	mlx_hook(m.win, 2, 1l<<0, key_check, &m);
	mlx_loop(m.mlx);
}
