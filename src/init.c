/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eclark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 16:18:09 by eclark            #+#    #+#             */
/*   Updated: 2022/08/26 14:05:53 by eclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_data *j, char **argv)
{
	j->kr = ft_atof(argv[2]);
	j->ki = ft_atof(argv[3]);
	j->max_r = 2.0;
	j->min_r = -2.0;
	j->min_i = -2.0;
	j->max_i = j->min_i + (j->max_r - j->min_r) * HEIGHT / WIDTH;
}

void	init_mandel(t_data *m)
{
	m->max_r = 1.0;
	m->min_r = -2.0;
	m->min_i = -1.5;
	m->max_i = m->min_i + (m->max_r - m->min_r) * HEIGHT / WIDTH;
}

void	init(t_data *f)
{
	int		bits_pp;
	int		line_size;
	int		endian;
	int		*data;

	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Mandelbrot");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	data = (int *)mlx_get_data_addr(f->img, &bits_pp, &line_size, &endian);
	f->data = data;
}
